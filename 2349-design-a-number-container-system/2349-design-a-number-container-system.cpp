class NumberContainers {
private:
    map<int,int>idx_to_val;
    map<int,set<int>>pos_of_val;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idx_to_val.count(index)==0)
        {
            idx_to_val[index] = number;
            pos_of_val[number].insert(index);
        }
        else{
            int pre_val = idx_to_val[index];
            pos_of_val[pre_val].erase(index);
            if(pos_of_val[pre_val].size()==0)
                pos_of_val.erase(pre_val);
            idx_to_val[index] = number;
            pos_of_val[number].insert(index);
        }
    }
    
    int find(int number) {
        if(pos_of_val.count(number)==0)
            return -1;
        return *pos_of_val[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */