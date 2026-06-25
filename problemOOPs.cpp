#include <iostream>
#include <string>
#include <list>
#include <vector>

class Postable{
    public:

    virtual std::string getPostId() = 0;
    virtual std::string getContent() = 0;
    virtual int getLikes() = 0;

    virtual ~Postable() = default;
};
class Post : public Postable{
    private:
    std::string postId;
    std::string content;
    int likes;

    public:
    Post(std::string postId, std::string content) : postId(postId) , content(content){
        likes = 0;
    }
    void addLike(){
        likes++;
    }
    std::string getPostId()override{
        return postId;
    }
    std::string getContent()override{
        return content;
    }
    int getLikes()override{
        return likes;
    }

    virtual ~Post() = default;
};
class UserProfile{
    private:
    std::string userId;
    std::string username;
    std::list<Post*> postPtr;

    public:
    UserProfile(std::string userId, std::string username) : userId(userId) , username(username){}

    ~UserProfile(){
        for(Post* p: postPtr) delete p;
    }
    std::string getUserId()const{
        return userId;
    }
    std::string getUsername()const{
        return username;
    }
    void createPost(std::string postId, std::string content){
        postPtr.push_back(new Post(postId  , content)) ; 
    }
    Post* getPostById(std::string postId){

        for(const auto& ptr: postPtr){
            if(ptr->getPostId() == postId){
                return ptr;
            }
        }
        return nullptr;
    }

    std::list<std::string> postList;

    std::list<Post*> getAllPost(){
        return postPtr;
    }

};
class SocialFeed{
    private:
    std::vector<UserProfile*> userProfile;

    public:

    ~SocialFeed(){
        for(UserProfile* u: userProfile) delete u;
    }
    
    void addUser(UserProfile* user){
        userProfile.push_back(user);
    }
    UserProfile* getUserById(std::string userId){

        for(const auto& ptr: userProfile){
            if(ptr->getUserId() == userId){
                return ptr;
            }
        }
        return nullptr;
    }
    std::string getFeedSummary(){
        std::string summary = "--- Summary ---\n";

        for(const auto& ptr: userProfile){
            summary += "UserId: " + ptr->getUserId() + "|   Username: " + ptr->getUsername() + "\n";

            for(const auto& pptr: ptr->getAllPost()){
                summary += "\n Post ID: " + pptr->getPostId() + "Content: " + pptr->getContent() + "Likes: " + std::to_string(pptr->getLikes()) + "\n" ;
            }
        }
        return summary;
    }
};

int main(){

    SocialFeed* feed = new SocialFeed();

    UserProfile* usr = new UserProfile("756840", "john756" );
    UserProfile* usr1 = new UserProfile("734238", "Carman654");

    usr->createPost("a3f323", "I am uploading Picture.");
    usr->createPost("75fhf", "I am uploading a song.");

    usr1->createPost("k234h4"  , "Uploading Video.");
    usr1->createPost("94ghr", "Uploading gif");


    feed->addUser(usr);
    feed->addUser(usr1);

    std::cout<< feed->getFeedSummary() << std::endl;

    delete feed;

    return 0;
}
