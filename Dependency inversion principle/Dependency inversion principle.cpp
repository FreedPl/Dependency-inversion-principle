#include <iostream>
#include <vector>
#include <memory>

// Абстрактний інтерфейс розробника
class IDeveloper
{
public:
    virtual void develop() = 0;
    virtual ~IDeveloper() = default;
};

// Реалізація фронтенд-розробника
class FrontEndDeveloper : public IDeveloper
{
public:
    void develop() override
    {
        std::cout << "Пишу JavaScript код\n";
    }
};

// Реалізація бекенд-розробника
class BackendDeveloper : public IDeveloper
{
public:
    void develop() override
    {
        std::cout << "Пишу Java код\n";
    }
};

// Модуль високого рівня, що залежить від абстракцій, а не реалізацій
class Project
{
    std::vector<std::shared_ptr<IDeveloper>> developers;

public:
    void addDeveloper(std::shared_ptr<IDeveloper> developer)
    {
        developers.push_back(developer);
    }

    void develop()
    {
        for (const auto& dev : developers)
        {
            dev->develop();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    // Створення конкретних розробників
    auto frontEndDev = std::make_shared<FrontEndDeveloper>();
    auto backEndDev = std::make_shared<BackendDeveloper>();

    // Модуль високого рівня залежить від абстракцій
    Project project;
    project.addDeveloper(frontEndDev);
    project.addDeveloper(backEndDev);

    project.develop();

    return 0;
}
