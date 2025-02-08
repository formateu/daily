class NumberContainers {
private:
    std::unordered_map<int, int> indToNumber;
    std::unordered_map<int, std::set<int>> numberToInd;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indToNumber.contains(index)) {
            const auto oldNumber = indToNumber[index];
            indToNumber[index] = number;
            numberToInd[oldNumber].erase(index);
            if (numberToInd[oldNumber].size() == 0 && oldNumber != number) {
                numberToInd.erase(oldNumber);
            }
            numberToInd[number].emplace(index);
        } else {
            indToNumber.emplace(index, number);
            if (numberToInd.contains(number)) {
                numberToInd[number].emplace(index);
            } else {
                numberToInd.emplace(number, std::set<int>{index});
            }
        }
    }
    
    int find(int number) {

        if (auto f = numberToInd.find(number); f != numberToInd.end()) {
            return *((*f).second.begin());
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */