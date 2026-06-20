#include <iostream>
#include <string>
#include <list>

class Manageable{

    public:
    virtual std::string getTaskId() = 0;
    virtual std::string updateStatus(std::string) = 0;

    virtual ~Manageable() = default;
};
class Task : public Manageable{
    private:
    std::string  taskId;
    std::string taskName;
    std::string status;

    public:
    Task(std::string taskId, std::string taskName) : taskId(taskId) , taskName(taskName), status("PENDING"){}

    std::string updateStatus(std::string newStatus)override{
        return ("Update stauts to: " + newStatus);
    }
    std::string getTaskId(){
        return taskId;
    }

};
class TaskManager{
    private:
    std::string managerName;
    std::list<Task*> tsk;

    public:
    TaskManager(std::string managerName) : managerName(managerName){};

    void addTask(Task* getTask){
        tsk.push_back(getTask);
    }
    Task* getTaskById(std::string taskId){
        std::string response;
        Task* ptr = nullptr;

        for(auto tskptr: tsk){
           response =  tskptr->getTaskId();

           if(taskId == response){
            return tskptr;
           }
           return ptr;
        }
    }

    std::string allTaskSummary(){
        std::string summary ;

        for(const auto& sumry: tsk){
            summary += sumry.
        }
    }

};

int main(){

    Task* task1 = new Task("AD43C32", "Clean Files");
    Task* task2 = new Task("BD34Z72", "Delete Log Files");
    Task* task3 = new Task("GR83T56", "Run Anti virus");

    TaskManager manager("Faisal");

        manager.addTask(task1);
        manager.addTask(task2);
        manager.addTask(task3);

        if(manager.getTaskById("BD34Z72") != nullptr){
            task2->updateStatus("Completed");
        }


        

    return 0;
}
