class TaskManager {
public:
    map<int,int> taskToUser; // [taskid] -> [userid]
    map<int,set<int>> priorityToTaskId;    
    map<int,int> taskToPriority;
    
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& x : tasks){
            int userId = x[0];
            int taskId = x[1];
            int priority = x[2];
            taskToUser[taskId] = userId;
            taskToPriority[taskId] = priority;
            priorityToTaskId[priority].insert(taskId);
        }
    }

    
    void add(int userId, int taskId, int priority) {
        priorityToTaskId[priority].insert(taskId);
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int originalPriority = taskToPriority[taskId];
        // remove from original priority
        priorityToTaskId[originalPriority].erase(taskId);
        // if set becomes empty, remove the priority entry
        if(priorityToTaskId[originalPriority].empty()) {
            priorityToTaskId.erase(originalPriority);
        }
        // add to new priority
        priorityToTaskId[newPriority].insert(taskId);
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskToPriority[taskId];
        priorityToTaskId[priority].erase(taskId);
        // if set becomes empty, remove the priority entry
        if(priorityToTaskId[priority].empty()) {
            priorityToTaskId.erase(priority);
        }
        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        // get the highest priority (last element in map)
        auto lastPriorityIt = priorityToTaskId.rbegin();
        if(lastPriorityIt == priorityToTaskId.rend()) {
            return -1; // or handle empty case as needed
        }
        
        // get the highest taskId from the set (last element)
        auto& taskSet = lastPriorityIt->second;
        int taskId = *taskSet.rbegin();
        
        // get userId before removing the task
        int userId = taskToUser[taskId];
        
        // remove the task
        rmv(taskId);
        
        return userId;
    }
};
