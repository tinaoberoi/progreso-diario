/*https://leetcode.com/problems/network-delay-time*/

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, list<pair<int, int>>> graph;
        for(auto time: times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(N+1, -1);
        /*
        for(auto j : graph){
            dist[j.first] = -1;
        }*/
        
        queue<pair<int, int>>q;
        q.push({K, 0});
        dist[K] = 0;
        
        while(!q.empty()){
            int len = q.size();
            for(int i =0; i<len; i++){
                auto p = q.front();
                q.pop();
                
                auto node = p.first;
                auto nodeTime = p.second;
                
                for(auto childPair : graph[node]){
                    if(nodeTime + childPair.second < dist[childPair.first] || dist[childPair.first] == -1){
                        dist[childPair.first] = nodeTime + childPair.second;
                        q.push({childPair.first, dist[childPair.first]});
                    }
                }
            }
        }
        int max_time = -1;
        for(int i =1; i<dist.size(); i++){
            cout<<"node "<<i<<" time "<<dist[i]<<endl;
            if(dist[i] == -1)
                return -1;
            max_time = max(max_time, dist[i]);  
        }
        return max_time;
    }