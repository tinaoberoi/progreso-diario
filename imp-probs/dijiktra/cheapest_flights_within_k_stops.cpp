/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/
#include<bits/stdc++.h>
using namespace std;

    int helper(int n, unordered_map<int, list<pair<int, int>>> m, int src, int dst, int k){
        vector<int>dist(n, -1);
        //set<pair<int, int>>s;
        //s.insert({0, src});
        queue<pair<int, int>> q; q.push({src, 0});
        dist[src] = 0;
        ++k;
        while(!q.empty()){
            if(!k) break;
            //auto p = *(s.begin());
            int len = q.size();
            for(int i = 0; i<len; i++){
            auto p = q.front();
            int node = p.first;
            int nodeDist = p.second;
            //s.erase(s.begin());
            q.pop();
            
            for(auto childPair : m[node]){
                
                if(nodeDist + childPair.second < dist[childPair.first] || dist[childPair.first] == -1){
                    int dest = childPair.first;
                    //auto f = s.find({dist[dest], dest});
                    //if(f != s.end()){
                    //    s.erase(f);
                    //}
                    dist[dest] = nodeDist + childPair.second;
                    //s.insert({dist[dest], dest});
                    q.push({dest, dist[dest]});
                }
            }}
            k--;
        }
        return dist[dst];
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> m;
        for(auto flight : flights){
            m[flight[0]].push_back({flight[1], flight[2]});
        }
        
        return helper(n, m, src, dst, k);
    }