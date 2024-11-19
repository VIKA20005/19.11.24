#include <iostream>
#include <string>


class Employer 
{
public:
    virtual void Print() const = 0;  
    virtual ~Employer() = default;   
};


class President : public Employer 
{
private:
    std::string name;
    int year_of_service;

public:
    President(const std::string& n, int y) : name(n), year_of_service(y) {}

    void Print() const override 
    {
        std::cout << "President: " << name << ", Years of service: " << year_of_service << std::endl;
    }
};


class Manager : public Employer 
{
private:
    std::string name;
    std::string department;

public:
    Manager(const std::string& n, const std::string& dept) : name(n), department(dept) {}

    void Print() const override 
    {
        std::cout << "Manager: " << name << ", Department: " << department << std::endl;
    }
};


class Worker : public Employer 
{
private:
    std::string name;
    int hours_per_week;

public:
    Worker(const std::string& n, int hours) : name(n), hours_per_week(hours) {}

    void Print() const override 
    {
        std::cout << "Worker: " << name << ", Hours per week: " << hours_per_week << std::endl;
    }
};

int main() 
{
    
    President president("John Doe", 10);
    Manager manager("Alice Smith", "Marketing");
    Worker worker("Bob Brown", 40);

    
    Employer* employees[] = { &president, &manager, &worker };

    
    for (Employer* e : employees) 
    {
        e->Print();  
    }

    return 0;
}