class Solution {
public:
    bool isUgly(int num) {
        bool isugly = true;
        bool iscalculated = false;
        if(num <= 1)
            return false;
        while(1)
        {
          iscalculated = false;
          if(num / 5 * 5 == num)
          {
              num /= 5;
              iscalculated = true;
          }
          if(num / 3 * 3 == num)
          {
              num /= 3;
              iscalculated = true;
          }
          if(num / 2 * 2 == num)
          {
              num /= 2;
              iscalculated = true;
          }
          if(!iscalculated)
          {
              if(num == 1)
                  isugly = true;
              else
                  isugly = false;
          }
        }
        return isugly;
    }
};