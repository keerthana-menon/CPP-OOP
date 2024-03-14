# include "ToDo.hpp"

// Counter variables
int Task::total = 0;
int Task::id = 1000;

// Sorts tuple according to the third element (here, the priority)
bool compHelper(const std::tuple<int, std::string, int, std::string> &a, const std::tuple<int, std::string, int, std::string> &b)
{
    return std::get<2>(a) > std::get<2>(b);
}

void menuPrint()
{
    std::cout << "Choose an option" << "\n";
    std::cout << "1. Add tasks\n2. Find task\n";
    std::cout << "3. Category-wise tasks\n4. Print all tasks\n";
    std::cout << "5. Priority-wise display\n6. Delete task\n";
    std::cout << "7. Exit\nChoice: ";
}

void linePrint()
{
    std::cout << "---------------------------------------------------------------------------------------------\n";
}

void header()
{
    std::cout << "TASK ID\t" << std::setw(30) << "TASK NAME";
    std::cout << std::setw(30) << "CATEGORY" << std::setw(20) << "TASK NAME";
    std::cout << "\n";
}

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TaskManager::printTasks(int id) const
{
    // header();
    // linePrint();
    std::cout << id << "\t" << std::setw(30) << taskList.at(id).getTaskName();
    std::cout << std::setw(30) << taskList.at(id).getCategory() << std::setw(20) << taskList.at(id).getPriority();
    std::cout << "\n";
}

void TaskManager::printTasks() const
{
    header();
    linePrint();
    for(auto iter = taskList.begin(); iter != taskList.end(); iter++)
    {
        std::cout << iter->first << "\t" << std::setw(30) << iter->second.getTaskName();
        std::cout << std::setw(30) << iter->second.getCategory() << std::setw(20) << iter->second.getPriority();
        std::cout << "\n";
    }
}

void TaskManager::createTask(std::string taskName, int priority, std::string category)
{
    if(priority >= 0 && priority <= 4)
    {
        Task t = Task(taskName, priority, category);
        taskList.insert(std::make_pair(Task::id, t));
        std::cout << "Task successfully added with task ID " << Task::id << "\n";
    }
    else
    {
        std::cout << "Priority should be in between 0 and 4!" << "\n";
    }
}

bool TaskManager::findTask(int id) const
{
    auto iter = taskList.find(id);
    if(iter != taskList.end())
    {
        header();
        linePrint();
        TaskManager::printTasks(id);
        return 1;
    }
    else
    {
        std::cout << "Task ID does not exist!" << "\n";
        return 0;
    }
}

void TaskManager::categorise(std::string category) const
{
    int count = 0;
    for(auto iter = taskList.begin(); iter != taskList.end(); iter++)
    {
        if(iter->second.getCategory() == category)
        {
            header();
            linePrint();
            TaskManager::printTasks(iter->first);
            count++;
        }
    }
    if(count == 0)
    {
        std::cout << "No tasks of the given category!\n";
    }
}

void TaskManager::sortPriorities() const
{
    std::vector<std::tuple<int, std::string, int, std::string>> temp;
    for(auto iter = taskList.begin(); iter != taskList.end(); iter++)
    {
        temp.vector::push_back(std::make_tuple(iter->first, iter->second.getTaskName(), iter->second.getPriority(), iter->second.getCategory()));
    }
    std::sort(temp.begin(), temp.end(), compHelper);
    header();
    linePrint();
    for(auto iter = temp.begin(); iter != temp.end(); iter++)
    {
        TaskManager::printTasks(std::get<0>(*iter));
    }
}

void TaskManager::deleteTask(int id)
{
    if(TaskManager::findTask(id))
    {
        taskList.erase(id);
        std::cout << "The above task has been deleted." << "\n";
    }
    else
    {
        std::cout << "Could not delete task." << "\n";
    }
}

void TaskManager::run()
{
    int choice;
    menuPrint();
    std::cin >> choice;
    linePrint();
    while(choice != 7)
    {
        switch(choice)
        {
            case 1: // Adding tasks
            {
                std::string t, c;
                int i;
                clearInput();
                std::cout << "Enter the task title: ";
                std::getline(std::cin, t);
                std::cout << "Enter the category of the task: ";
                std::getline(std::cin, c);
                std::cout << "Enter the priority from 0(least) to 4(high): ";
                std::cin >> i;
                clearInput();
                linePrint();
                TaskManager::createTask(t, i, c);
                linePrint();
                break;
            }
            case 2: // Find a task
            {
                int i;
                clearInput();
                std::cout << "Enter the task ID: ";
                std::cin >> i;
                clearInput();
                linePrint();
                TaskManager::findTask(i);
                linePrint();
                break;
            }
            case 3: // Categorise tasks
            {
                std::string c;
                clearInput();
                std::cout << "Enter the category to be viewed: ";
                std::getline(std::cin, c);
                linePrint();
                TaskManager::categorise(c);
                linePrint();
                break;
            }
            case 4: // Display all tasks
            {
                clearInput();
                linePrint();
                TaskManager::printTasks();
                linePrint();
                break;
            }
            case 5: // Priority-wise view
            {
                clearInput();
                linePrint();
                TaskManager::sortPriorities();
                linePrint();
                break;
            }
            case 6: // Delete task
            {
                int i;
                clearInput();
                std::cout << "Enter the ID of the task to be deleted: ";
                std::cin >> i;
                linePrint();
                TaskManager::deleteTask(i);
                linePrint();
                break;
            }
            default :
            {
                clearInput();
                linePrint();
                std::cout << "INVALID CHOICE! TRY AGAIN.\n";
                linePrint();
                break;
            }
        }
        menuPrint();
        std::cin >> choice;
        linePrint();
    }
    std::cout << "Thank you for using my to-do list program.\n";
}
