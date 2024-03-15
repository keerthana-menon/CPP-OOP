# ifndef _TODO_H
# define _TODO_H
# include <algorithm>
# include <iostream>
# include <iomanip>
# include <map>
# include <string>
# include <tuple>
# include <utility>
# include <vector>

class Task
{
    friend class TaskManager;
    private:
        static int total;
        static int id;
        std::string taskName;
        std::string category;
        int priority;
    
    public:
        // Constructor and destructor
        Task(std::string t, int i, std::string c) 
        {
            taskName = t;
            priority = i;
            category = c;
            total++;
            id++;
        }
        ~Task()
        {
            total--;
        }

        // Getters and setters
        void setTaskName(std::string t)
        {
            taskName = t;
        }
        std::string getTaskName() const
        {
            return taskName;
        }
        void setCategory(std::string c)
        {
            category = c;
        }
        std::string getCategory() const
        {
            return category;
        }
        void setPriority(int i)
        {
            priority = i;
        }
        int getPriority() const
        {
            return priority;
        }
};

class TaskManager 
{
    private:
        std::map<int, Task> taskList;
        bool emptyCheck() const;
    public:
        void createTask(std::string t, int i, std::string c);
        bool findTask(int d) const;
        void categorise(std::string c) const;
        void printTasks() const; // All tasks
        void printTasks(int d) const; // Specific task
        void sortPriorities() const; 
        void deleteTask(int d);
        void run();
};

# endif