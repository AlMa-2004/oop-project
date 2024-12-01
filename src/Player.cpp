#include "../headers/Player.h"

Player::Player()
    : playerName("Player"), playerMoney(0)
{
    //::cout << "Default player constructor\n";
}

// Parameterized constructor: initializes player with given name and money
Player::Player(std::string name, const int money)
    : playerName(std::move(name)), playerMoney(money)
{
    //std::cout << "Parameterized player constructor\n";
}

/*
Player::Player(const Player& p)
    : playerName(p.playerName), playerMoney(p.playerMoney)
{
    std::cout << "Copy player constructor\n";
    for (const auto& item : p.playerInventory)
    {
        playerInventory.push_back(std::make_unique<Item>(*item));
    }
}
*/

//OPERATOR OVERLOADING
/*
Player& Player::operator=(const Player& p)
{
    playerName = p.playerName;
    playerMoney = p.playerMoney;
    playerInventory.clear();

    for (const auto& item : p.playerInventory)
    {
        playerInventory.push_back(std::make_unique<Item>(*item));
    }
    std::cout << "Player assignment\n";
    return *this;
}
*/
std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << "PlayerName: " << player.playerName
        << " Money: " << player.playerMoney
        << " Inventory: ";
    // showInventory();

    return os;
}

void Player::addItem(const std::shared_ptr<Item>& i)
{
    for (auto& item : playerInventory)
    {
        if (item->getName() == i->getName())
        {
            item->setQuantity(item->getQuantity() + i->getQuantity());
            return;
        }
    }
    playerInventory.push_back(i);
    std::cout<<"Added item: "<<i->getName()<<" succesfully!\n";
}


std::vector<std::shared_ptr<Item>>::iterator Player::searchItem(const std::string& itemName)
{
    return std::ranges::find_if(playerInventory.begin(), playerInventory.end(),
                                [&itemName](const std::shared_ptr<Item>& item)
                                {
                                    return item->getName() == itemName;
                                });
}

void Player::removeItem(const std::string& s, const int q)
{
    auto found = searchItem(s);
    if (found != playerInventory.end())
    {
        if (q == (*found)->getQuantity())
            playerInventory.erase(found);
        else
            (*found)->setQuantity((*found)->getQuantity() - q);
    }
}


void Player::sellItem(const std::string& s, const int q)
{
    auto found = searchItem(s);
    if (found != playerInventory.end())
        playerMoney += (*found)->calculateSellingPrice(q);
    removeItem(s, q);
}

void Player::showInventory() const
{
    for (const auto& item : playerInventory)
        std::cout << *item << " ";
}

int Player::getMoney() const
{
    return playerMoney;
}
