#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
class Solution{
private:
    std::thread update_thread;
    const unsigned int update_interval ; // update after every 50 milliseconds
public:
    std::atomic<bool> running;
    Solution():running{true}, update_interval{50}{
        update_thread = std::thread(&Solution::update, this, std::ref(running), update_interval);
    };
    ~Solution(){
        if(update_thread.joinable())
            update_thread.join();
    }
    void update( std::atomic<bool>& program_is_running, unsigned int update_interval_millisecs );
};
void Solution::update( std::atomic<bool>& program_is_running, unsigned int update_interval_millisecs )
{
    const auto wait_duration = std::chrono::milliseconds(update_interval_millisecs) ;
    int i = 0;
    while( program_is_running )
    {
        std::cout << "update stuff: " << i++ << "\n" << std::flush ;
        std::this_thread::sleep_for(wait_duration) ;
    }
}

int main()
{
    std::cout << "*** press enter to exit the program gracefully\n\n" ;
    Solution su;
    // do other stuff in parallel: simulated below
    std::cin.get() ;

    // exit gracefully
    su.running = false ;
    std::cout << "finish\n";
}