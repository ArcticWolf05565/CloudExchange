#include <iostream>
#include <string>

class AppConfig{
    private:
    static AppConfig* instance;
    std::string appName;
    std::string version;
    static int instanceCount;
    
    AppConfig(std::string appName, std::string version){
        this->appName = appName;
        this->version = version;
        instanceCount++;
    }
    public:
    static AppConfig* getInstance(std::string appName, std::string version){
        if(instance == nullptr){
            instance = new AppConfig(appName , version);
        }
        return instance;
    }
    static int getInstanceCount();

    std::string getAppName(){
        return appName;
    }
    std::string getVersion(){
        return version;
    }
};

AppConfig* AppConfig::instance = nullptr;
int AppConfig::instanceCount = 0;

int AppConfig::getInstanceCount(){
    return instanceCount;
};

int main(){

    AppConfig* app = AppConfig::getInstance("Whatapp", "2.01");

    std::cout<< app->getInstanceCount() <<std::endl;

    AppConfig* app1 = AppConfig::getInstance("Whatapp", "2.01");

    std::cout<< app->getInstanceCount() <<std::endl;

    AppConfig* app2 = AppConfig::getInstance("Whatapp", "2.01");

    std::cout<< app->getInstanceCount() <<std::endl;

    std::cout<< app->getAppName() << std::endl;
    std::cout<< app->getVersion() << std::endl;


    return 0;
    
}