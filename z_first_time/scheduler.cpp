#include <iostream>
#include <queue>
#include <vector>
#include <functional>

// Define a structure for a Task
struct Task {
    int id;          // Task ID
    int priority;    // Task priority (higher value = higher priority)

    // Custom comparator for max-heap (default behavior of std::priority_queue)
    bool operator<(const Task& other) const {
        return priority < other.priority; // Higher priority comes first
    }
};

// Scheduler class
class Scheduler {
private:
    std::priority_queue<Task> taskQueue; // Priority queue to hold tasks

public:
    // Add a task to the scheduler
    void addTask(int id, int priority) {
        taskQueue.push({id, priority});
        std::cout << "Task " << id << " with priority " << priority << " added.\n";
    }

    // Execute the highest-priority task
    void executeTask() {
        if (taskQueue.empty()) {
            std::cout << "No tasks to execute.\n";
            return;
        }

        Task currentTask = taskQueue.top(); // Get the highest-priority task
        taskQueue.pop();                   // Remove it from the queue

        std::cout << "Executing Task " << currentTask.id 
                  << " with priority " << currentTask.priority << ".\n";
    }

    // Check if the scheduler is empty
    bool isEmpty() const {
        return taskQueue.empty();
    }
};

int main() {
    Scheduler scheduler;

    // Add tasks to the scheduler
    scheduler.addTask(1, 10);  // Task ID 1, Priority 10
    scheduler.addTask(2, 20);  // Task ID 2, Priority 20
    scheduler.addTask(3, 15);  // Task ID 3, Priority 15

    // Execute tasks in order of priority
    while (!scheduler.isEmpty()) {
        scheduler.executeTask();
    }

    return 0;
}
