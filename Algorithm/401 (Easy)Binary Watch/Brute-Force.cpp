class Solution {

    void generateNumbers(int bits, long temp_num, set<long>& numbers){
        if (bits == 0){
            numbers.insert(temp_num);
            return;
        }
        
        // If we have bits available, out of all 10 available bits, we need to do the follwoing:
        // For all bits (from 0 to 1 << 9)
        // Check if the bit is already set in the temporary number.
        // If the bit is set, do nothing, move to the other bit.
        // If the bit is not set, mark it as set in the temporary number, decrease the number of available bits
        // And call the method recursively.
        for (int i = 0; i < 10; ++ i){
            int temp_mask = (1 << i);
            if (temp_num & temp_mask){
                continue;           // The bit is set.
            }
            int tmp = temp_num;
            temp_num |= temp_mask;
            generateNumbers(bits - 1, temp_num, numbers);
            temp_num = tmp;
        }
    }    
    
    // Bitmask for minutes: 0000111111b = 15 + 16 + 32 = 59 = 0x3F
    // Bitmask for hours: 1111000000 = 0x3C0
    vector<string> extractHoursAndMinutes(set<long>& numbers){
        vector<string> res;
        // We know that the hours are the first 4 bits and the minutes are the last 6 bits.
        for (const auto& elem : numbers){
            int minutes = elem & 0x003F;
            int hours = (elem & 0x03C0) >> 6;
            if (minutes > 59 || hours > 11){
                continue;
            }
            string string_hour = to_string(hours);
            string string_minute = to_string(minutes);
            if (string_minute.size() == 1){
                string_minute = "0" + string_minute;
            }
            res.push_back(string_hour + ":" + string_minute);
        }
        return res;
    }
    
    
public:
    vector<string> readBinaryWatch(int num) {
        set<long> all_numbers;
        generateNumbers(num, 0, all_numbers);
        vector<string> result;
        result = extractHoursAndMinutes(all_numbers);
        // After we have all numbers, map them to the mask for extracting hours and minutes.
        return result;
    }
};
