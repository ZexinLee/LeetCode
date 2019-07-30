class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<std::string, int> map;
        for (const auto& cp : cpdomains)
        {
            int idx = cp.find(' ');
            int count = std::stoi(cp.substr(0, idx));
            while (idx != std::string::npos)
            {
                map[cp.substr(idx+1)] += count;
                idx = cp.find('.', idx+1);
            }
        }
        std::vector<std::string> ret;
        for (const auto& p : map)
        {
            ret.emplace_back(std::to_string(p.second) + ' ' + p.first); 
        }
        return ret;
    }
};