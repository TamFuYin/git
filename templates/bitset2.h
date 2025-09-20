#include<bits/stdc++.h>
#include<bitset>
namespace bs2{
    template<size_t _size=32>
    struct bitset{
        private:
            typedef word=unsigned int;
            std::vector<word> _v(_size);
        public:
            word operator[](size_t pos){
                return _v[pos];
            }
            bitset& operator&(const bitset&)
    };
}