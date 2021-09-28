class StockSpanner {
public:
    vector<int> stockPrice;
    stack<int> indStack;
    int ind;
    
    StockSpanner() {
        indStack.empty();
        stockPrice.clear();
        ind = 0;
    }
    
    int next(int price) {
        stockPrice.push_back(price);
        
        while(!indStack.empty() && stockPrice[indStack.top()] <= price) {
            indStack.pop();
        }
        
        int span;
        if(indStack.empty()) span = ind + 1;
        else span = ind - indStack.top();
        indStack.push(ind);
        ind++;
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */