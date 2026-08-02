 int lastStoneWeight(vector<int>& stones) {
      if(stones.size()==0) return 0;

      priority_queue<int>p;

      for(int i =  0 ; i < stones.size() ; i++){
         p.push(stones[i]);
      }  

      while(p.size() > 1){
        int stone1 = p.top();
        p.pop();

        int stone2 = p.top();
        p.pop();

        if(stone1 != stone2){
            p.push(stone1 - stone2);
        }

        else continue;
      }

      return (p.size()==0) ? 0 : p.top();
    }
};