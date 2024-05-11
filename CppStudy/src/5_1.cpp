#include <iostream>
struct AccountDatabase {
  virtual ~AccountDatabase() = default;
  virtual double retrieveAmount(long id) = 0;
  virtual void setAmount(double amount, long id) = 0;
};

struct inMemoryAccountDatabase : AccountDatabase {
  inMemoryAccountDatabase() = default;
  double retrieveAmount(long id) override {
    std::cout << "retrieve amount for account with ID: " << id;
    return 1000;
  };

  void setAmount(double amount, long id) override {
    std::cout << "Setting amount for account with ID: " << id << " to "
              << amount << std::endl;
  }

  ~inMemoryAccountDatabase() = default;
};
