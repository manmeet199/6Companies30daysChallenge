#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<course> courses(numCourses, 0);
    
    for(int i = 0; i<numCourses; i++)   
        courses[i] = course(i);
        
    for(auto i:prerequisites)           
        courses[i[0]].post.push_back(i[1]);
    
    for(auto& i:courses) 
        if(i.timein == -1)
            dfs(i, courses);
    
    for(auto i:prerequisites)
        if(courses[i[0]].timeout < courses[i[1]].timeout) return {};
        
    return sorted;
    }
    
    
private:
    int time = 0;
    vector<int> sorted;
    class course{
    public:
        int number;
        int timein;
        int timeout;
        vector<int> post;
        course(int a): number{a}, timein{-1}, timeout{-1} {}
    };
    
    void dfs(course& root, vector<course>& courses){
    root.timein = ++time;
    for(int i:root.post)
        if(courses[i].timein == -1)
            dfs(courses[i], courses);
    root.timeout = time++;
    sorted.push_back(root.number);
    return;
    }
};