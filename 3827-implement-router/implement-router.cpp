// // class Router {
// // public:
// //     int size;
// //     // set<vector<int>>st;
// //     //queue<vector<int>> q;
// //     unordered_map<string, vector<int>>mp;
// //     queue<string>q;
// //     int currCount=0;
// //     Router(int memoryLimit) {
// //         size = memoryLimit;
// //     }
    
// //     bool addPacket(int source, int destination, int timestamp) {
// //         // i need to manage not to make them so i will get them
// //          vector<int>vpacket = {source, destination, timestamp};
// //         string packet = to_string(source)+"_"+to_string(destination)+"_"+to_string(timestamp);
// //         auto it = mp.find(packet);
// //         if(it!= mp.end()) return false  ;
// //         else if(currCount>=size){
// //             currCount--;
// //             // vector<int>forward= q.front();
// //             string forward = q.front();
// //             q.pop();
// //             mp.erase(forward);
// //         }
// //         currCount++;
// //         mp[packet]= vpacket;
// //         q.push(packet);
// //         return true;
// //     }
    
// //     vector<int> forwardPacket() {
// //         if (q.empty()) return{};
// //         // vector<int>forward= q.front();
// //         string forward  = q.front();
// //         vector<int>ans= mp[forward];
// //         q.pop();
// //         mp.erase(forward);
// //         currCount--;
// //         return ans;
// //     }
    
// //     int getCount(int destination, int startTime, int endTime) {
// //         int count=0;
// //         for(const auto &it: mp )
// //             if(it.second[1]== destination&& (it.second[2]>=startTime &&it.second[2]<=endTime)) count ++;
// //             return count;
// //     }
// // };

// // /**
// //  * Your Router object will be instantiated and called as such:
// //  * Router* obj = new Router(memoryLimit);
// //  * bool param_1 = obj->addPacket(source,destination,timestamp);
// //  * vector<int> param_2 = obj->forwardPacket();
// //  * int param_3 = obj->getCount(destination,startTime,endTime);
// //  */

// class Router {
// public:
//     int size;
//     unordered_map<string, vector<int>> mp;
//     queue<string> q;
//     int currCount = 0;
//     unordered_map<int, vector<int>>t;
//     Router(int memoryLimit) {
//         size = memoryLimit;
//     }

//     bool addPacket(int source, int destination, int timestamp) {
//         vector<int> vpacket = {source, destination, timestamp};
//         string packet = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

//         if (mp.find(packet) != mp.end()) return false;

//         if (currCount >= size) {
//             string forward = q.front();
//             q.pop();
//             mp.erase(forward);
//             currCount--;
//         }
//         t[destination].push_back(timestamp);
//         mp[packet] = vpacket;
//         q.push(packet);
//         currCount++;
//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (q.empty()) return {};

//         string forward = q.front();
//         vector<int> ans = mp[forward];
//         q.pop();
//         mp.erase(forward);
//         currCount--;
//         return ans;
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         int count = 0;
//         for (const auto& it : t[destination]) {
//            if(it>=startTime&&it<=endTime) count++;
//         }
//         return count;
//     }
// };
struct packet{
    int source, destination, timestamp;
    packet(int source,int destination,int timestamp){
        this->source=source;
        this->destination=destination;
        this->timestamp=timestamp;
    }
    string getUniqueId(){
        return to_string(source)+"_"+to_string(destination)+"_"+to_string(timestamp);
    }
};
class Router {
    unordered_set<string>packetEntried;
    queue<packet>q;
    unordered_map<int,deque<int>>umap;
    int memoryLimit;
public:
    Router(int memoryLimit) {
        this->memoryLimit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        packet new_pkt(source,destination,timestamp);
        string id=new_pkt.getUniqueId();
        if(packetEntried.count(id)){
            return false;
        }
        packetEntried.insert(id);
        umap[destination].push_back(timestamp);
        q.push(new_pkt);
        if(q.size()>memoryLimit){
            packet pckt=q.front();
            int destination=pckt.destination;
            packetEntried.erase(pckt.getUniqueId());
            q.pop();
            umap[destination].pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0){
            return {};
        }
        packet pckt=q.front();
        q.pop();

        packetEntried.erase(pckt.getUniqueId());
        umap[pckt.destination].pop_front();
        return {pckt.source,pckt.destination,pckt.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int startInd=lower_bound(umap[destination].begin(),umap[destination].end(),startTime)-umap[destination].begin();
        int lastInd=upper_bound(umap[destination].begin(),umap[destination].end(),endTime)-umap[destination].begin();
        return lastInd-startInd;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */