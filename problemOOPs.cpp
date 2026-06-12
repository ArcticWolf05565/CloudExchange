#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Product{
    private:
    std::string productId;
    std::string productName;
    double basePrice;
    static int totalProducts;

    public:
    Product(std::string productId, std::string productName, double basePrice) : productId(productId) , productName(productName), basePrice(basePrice){
        totalProducts++ ;
    }
    // std::tuple<std::string, std::string, double> getAttributes() const {
    //     return {productId, productName, basePrice};
    // } //i was just tying some new thing but i realised it is making redundency across the code so i leave this 

    std::string getProductId()const{
      return productId;   
    }
    std::string getProductName()const{
        return productName;
    }
    double getBasePrice()const{
        return basePrice;
    }

    static int getTotalProducts();

    virtual double getFinalPrice() = 0;

    virtual ~Product()  = default;
};
class Discountable{
    public:
    virtual double applyDiscount(double percentage) = 0;
    virtual ~Discountable() = default;
};
class Taxable{
    public:
    virtual double applyTax(double taxRate) = 0;
    virtual ~Taxable() = default;
};
class ElectronicProduct : public Product , public Discountable, public Taxable{
    private:
    std::string brand;

    public:
    ElectronicProduct(std::string productId, std::string productName, double basePrice, std::string brand ) : Product(productId, productName, basePrice), brand(brand){}
    
    double getFinalPrice()override{

        return(getBasePrice() + applyTax(0.18));
        
    }
    double applyDiscount(double percentage)override{
        return (getBasePrice() - (getBasePrice() * percentage / 100));
    }
    double applyTax(double taxRate)override{
        return (getBasePrice() * taxRate);
    }
};

int Product::totalProducts = 0;
int Product::getTotalProducts(){
    return totalProducts;
};
class ClosthingProduct : public Product, public Discountable{
    private:
    std::string size;

    public:
    ClosthingProduct(std::string productId, std::string productName, std::string size, double basePrice) : Product(productId, productName, basePrice) , size(size){};

    double getFinalPrice()override{
        return (getBasePrice() - applyDiscount(10));
    }
    double applyDiscount(double percentage)override{
        return (getBasePrice() * percentage / 100);
    }
};
class Order{
    private:
    std::string orderId;
    Product* item;
    static int totalOrders;

    public:
    Order(std::string orderId, Product* item) : orderId(orderId), item(item) {
        totalOrders++;
    }

    std::string getOrderSummary()const{
        std::ostringstream tempPrice;

        tempPrice << std::fixed << std::setprecision(2) << item->getFinalPrice();

        return ("Order ID: " + orderId + "\n"
        + "Product name: " + item->getProductName() + "\n" 
        + "Final price: " + tempPrice.str() + "\n");
    }
    static int getTotalOrder();

    ~Order() = default;
};

int Order::totalOrders = 0;
int Order::getTotalOrder(){
    return totalOrders;
};

int main(){

    ElectronicProduct mobile("A2-4C781", "Iphone", 95000, "Apple");
    ClosthingProduct  appreal("A3-5A7", "Jeans", "Large", 2100);

    Order piece("20-AC354845G12", &mobile);
    Order piece2("20-BC549545R32", &appreal);

    std::cout << piece.getOrderSummary() << std::endl;
    std::cout << piece2.getOrderSummary() << std::endl;

    std::cout<< "Total Products: " << Product::getTotalProducts() << std::endl;
    std::cout<< "Total Orders: " << Order::getTotalOrder() << std::endl;
    return 0;
}