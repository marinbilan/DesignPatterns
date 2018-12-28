#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "Feature0/if/FeatureIf.h"
#include "Feature0/h/Feature.h"

#include <gmock/gmock.h>

/*class myClass
{
public:
        myClass(int value) : m_value(value) {}
        
int m_value;
};*/


// Object For Test
/*
class BankAccount
{
public:
    BankAccount(int balance) : m_balance(balance)
    {
	std::cout << " Calling BankAccount Constructor. Balance = " << balance << std::endl;
    }
    virtual ~BankAccount()
    {
	std::cout << " Calling BankAccount Destructor." << std::endl;
    }

    void deposit(int amount)
    {
	m_balance += amount;
    }

    bool withdraw(int amount)
    {
    }

int m_balance;
};*/

struct BankAccount
{
    int balance = 0;

    BankAccount() {}
    
    explicit BankAccount(const int balance) : balance{balance}
    {
	//std::cout << " Calling BankAccount Constructor. Balance = " << balance << std::endl;
    }

    virtual ~BankAccount()
    {
	//std::cout << " Calling BankAccount Destructor." << std::endl;
    }

    void deposit(int amount)
    {
	balance += amount;
    }

    bool withdraw(int amount)
    {
        if(amount <= balance) 
        {
            balance -= amount;
            return true;
        }

        return false;
    }
};

// TEST FIXTURE
// Test Fixture must be struct
struct BankAccountTest : testing::Test
{
BankAccount* account;

    BankAccountTest()
    {
	//std::cout << " Calling BankAccountTest Constructor. " << std::endl;
	account = new BankAccount(0);
    }
    ~BankAccountTest()
    {
	//std::cout << " Calling BankAccountTest Destructor. " << std::endl;
	delete account;
    }
};

// 1 TEST
// Very Important TEST_F with capital letters!
// Test need to have F because we use fixture
// 1st param: Name of fixture
// 2nd param: Name of test
TEST_F(BankAccountTest, BankAccountStartsEmpty)
{
    // BankAccount account(0); // We don't need this.. Already have everything in Test Fixture
    EXPECT_EQ(0, account->balance);
}

// 2 TEST
TEST_F(BankAccountTest, CanDepositMoney)
{
    // BankAccount account(0); // We don't need this.. Already have everything in Test Fixture
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}


struct account_state
{
    // SET
    int initial_balance;
    int withdraw_amount;
    // EXPECT
    int final_balance;
    bool success;
};


// PARAM FIXTURE
// Fixture for parametrize test
// Each time take new param value for balace
struct WithDrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state>
{
    // Initialize Starting Amount of balance in constructor
    WithDrawAccountTest()
    {
	// 1] Set First Param initial_balance
	account->balance = GetParam().initial_balance;
    }
};

TEST_P(WithDrawAccountTest, FinalBalance)
{
    // 1] 
    account_state as = GetParam();

    // 2] Set Second Param withdraw_amount
    bool success = account->withdraw(as.withdraw_amount);

    EXPECT_EQ(as.final_balance, account->balance);
    EXPECT_EQ(as.success, success);
}

// Test Starts from position in which you define data
INSTANTIATE_TEST_CASE_P(Default, WithDrawAccountTest, 
    testing::Values(
    account_state{100, 50, 50, true},
    account_state{100, 200, 100, false})
);




































