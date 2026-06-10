# C++ OOP Practice Questions — Set 3 (Advanced Level)

> **C++ vs Java — Key Differences to keep in mind:**
> - `String` → `std::string` (include `<string>`)
> - `System.out.println()` → `std::cout <<`
> - No `interface` keyword → use **pure abstract class** (`virtual method() = 0`)
> - `super()` → use **initializer list** (`: ParentClass(args)`)
> - `static` methods called as `ClassName::methodName()`
> - Arrays → use `std::vector` (include `<vector>`)
> - `this()` constructor chaining → use **delegating constructors** (C++11)
> - Always add **destructor** `~ClassName() {}` in classes with inheritance
> - Use `virtual` keyword for methods you want to override
> - Use `override` keyword when overriding in child class

---

## Question 1 — Encapsulation + Validation Logic

You are building a registration system for a gym.

- Create a class called `GymMember` with private variables `std::string memberName`, `int age`, and `std::string membershipType` (values can only be `"basic"`, `"premium"`, or `"vip"`)
- Add a constructor `GymMember(std::string memberName, int age, std::string membershipType)` that sets all three values
- Add getter methods `getMemberName()`, `getAge()`, and `getMembershipType()` — each must **return** the value, not print it
- Add a setter `setMembershipType(std::string membershipType)` that updates the membership only if the value is `"basic"`, `"premium"`, or `"vip"` — otherwise return a `std::string` message `"Invalid membership type"`
- Add a method `getMemberInfo()` that **returns** a `std::string` containing all three values
- In the `main` function, create a `GymMember` object, print all info using `getMemberInfo()`, try setting a valid and an invalid membership type, and print the membership type after each attempt using `getMembershipType()`

---

## Question 2 — Inheritance + Method Overriding

You are building a system for an online learning platform.

- Create a parent class called `Course` with private variables `std::string courseName` and `int durationInHours`, and a constructor `Course(std::string courseName, int durationInHours)` that sets both values using an **initializer list**
- Add getter methods `getCourseName()` and `getDuration()` that **return** their respective values
- Add a `virtual` method `getCourseDetails()` that **returns** a `std::string` containing course name and duration
- Create two child classes — `VideoCourse` with an additional private variable `std::string instructor` and `QuizCourse` with an additional private variable `int numberOfQuizzes`
- Each child class must call the parent constructor using initializer list — `: Course(courseName, durationInHours)`
- Each child class must override `getCourseDetails()` using the `override` keyword — call `Course::getCourseDetails()` and append its own info — the method must **return** a `std::string`, not print
- Use primitive `int` for `numberOfQuizzes`
- Add a `virtual` destructor `~Course() {}` in the parent class
- In the `main` function, create one `VideoCourse` and one `QuizCourse` object, and print their details using `std::cout`

---

## Question 3 — Polymorphism + Meaningful Logic

You are building a notification dispatch system for a hospital.

- Create a parent class called `Alert` with a variable `std::string recipientName` and a constructor `Alert(std::string recipientName)`
- Add a `virtual` method `sendAlert(std::string message)` that **returns** a `std::string` — `"Sending generic alert to " + recipientName + ": " + message`
- Create three child classes — `DoctorAlert`, `PatientAlert`, and `NurseAlert` — each overriding `sendAlert(std::string message)` using the `override` keyword
- `DoctorAlert` must prepend `"[URGENT] "` to the message
- `PatientAlert` must append `" - Please stay calm."` to the message
- `NurseAlert` must prepend `"[ACTION REQUIRED] "` to the message
- Each child class must call `Alert::sendAlert(message)` and build on top of it — do not duplicate the base logic
- Add a `virtual` destructor `~Alert() {}` in the parent class
- In the `main` function, create a `std::vector<Alert*>` containing pointers to all three objects, loop through it calling `sendAlert()`, and print each result — remember to `delete` each pointer after use

---

## Question 4 — Abstract Class + Return Types

You are building a tax calculation system for a company.

- Create an abstract class called `TaxCalculator` with private variables `std::string entityName` and `double income`, and a constructor `TaxCalculator(std::string entityName, double income)` that sets both values using an **initializer list**
- Add getter methods `getEntityName()` and `getIncome()` that **return** their values
- Add a **pure virtual** method `calculateTax()` that returns a `double` — declare it as `virtual double calculateTax() = 0`
- Add a non-abstract method `getTaxReport()` that **returns** a `std::string` — it must call `calculateTax()` internally and include the entity name, income, and calculated tax in the returned string — use `std::to_string()` to convert numbers to string
- Create two concrete classes — `IndividualTax` that calculates tax as `income * 0.1` and `CorporateTax` that calculates tax as `income * 0.25`
- Each concrete class must call `TaxCalculator(entityName, income)` in its initializer list
- Add a `virtual` destructor `~TaxCalculator() {}` in the abstract class
- In the `main` function, create one `IndividualTax` and one `CorporateTax` object, and print `getTaxReport()` for each — all printing in `main`

---

## Question 5 — Abstract Classes as Interfaces + Multiple Inheritance

You are building a system for a smart security camera.

> **C++ Note:** C++ has no `interface` keyword. Use **pure abstract classes** instead. Multiple inheritance is allowed in C++.

- Create a pure abstract class called `Recordable` with pure virtual methods `startRecording()` and `stopRecording()` — both return `std::string`
- Create a pure abstract class called `MotionDetectable` with a pure virtual method `detectMotion(std::string zone)` that returns `std::string` — the `zone` parameter must be used in the returned message
- Create a pure abstract class called `Alertable` with a pure virtual method `triggerAlert(std::string reason)` that returns `std::string` — the `reason` parameter must be used in the returned message
- Create a class called `SecurityCamera` with a private variable `std::string cameraId` and a constructor `SecurityCamera(std::string cameraId)` that inherits from all three pure abstract classes using `: public Recordable, public MotionDetectable, public Alertable`
- All methods must use `cameraId` in their returned messages
- Add virtual destructors in all pure abstract classes
- In the `main` function, create a `SecurityCamera` object and call all methods, printing each result

---

## Question 6 — Constructor Overloading + Delegating Constructors

You are building a product catalog system for a store.

- Create a class called `Product` with private variables `std::string productName`, `std::string category`, `double price`, and `int stock`
- Add four constructors:
  - `Product(std::string productName)` — sets only name, category defaults to `"Uncategorized"`, price to `0.0`, stock to `0`
  - `Product(std::string productName, std::string category)` — sets name and category, price to `0.0`, stock to `0`
  - `Product(std::string productName, std::string category, double price)` — sets name, category and price, stock to `0`
  - `Product(std::string productName, std::string category, double price, int stock)` — sets all four
- Each constructor must use **delegating constructors** (C++11) to call the next constructor — do not repeat assignment logic. Example: `Product(std::string name) : Product(name, "Uncategorized") {}`
- Add a method `getProductInfo()` that **returns** a `std::string` containing all four values — use `std::to_string()` for numbers
- In the `main` function, create four `Product` objects using each constructor and print their info using `getProductInfo()`

---

## Question 7 — Static Members + Singleton Pattern

You are building a configuration manager for an application.

- Create a class called `AppConfig` with a private static pointer `static AppConfig* instance` (initially `nullptr`), private variables `std::string appName` and `std::string version`, and a **private** constructor `AppConfig(std::string appName, std::string version)` that sets both values and increments a static `int instanceCount`
- Add a static method `getInstance(std::string appName, std::string version)` that creates a new `AppConfig` object using `new` only if `instance` is `nullptr`, otherwise returns the existing one — this is called the **Singleton pattern**
- Add a static method `getInstanceCount()` that **returns** `instanceCount`
- Add getter methods `getAppName()` and `getVersion()` that **return** their values
- Initialize static members outside the class: `AppConfig* AppConfig::instance = nullptr;` and `int AppConfig::instanceCount = 0;`
- In the `main` function, call `getInstance()` three times with different values, print `getAppName()` and `getVersion()` for each returned pointer, and print `getInstanceCount()` — observe that all three calls return the same object and count stays at `1`

---

## Question 8 — Function Overloading + Return Types

You are building a string utility class for a text processing app.

- Create a class called `StringUtils` with overloaded method `format()`
- Add the following versions:
  - `format(std::string text)` — returns the text in **uppercase** using `std::transform` and `::toupper`
  - `format(std::string text, int repeatCount)` — returns the text repeated `repeatCount` times separated by a space
  - `format(std::string text, bool addBrackets)` — returns the text wrapped in square brackets `[text]` if `addBrackets` is `true`, otherwise returns as-is
  - `format(std::string text, std::string prefix, std::string suffix)` — returns the text with the given prefix and suffix attached
- All methods must **return** a `std::string`, not print
- In the `main` function, call all four versions with sample values and print each result with a label

---

## Question 9 — Composition + Multiple Objects

You are building a school management system.

- Create a class called `Teacher` with private variables `std::string teacherName` and `std::string subject`, a constructor `Teacher(std::string teacherName, std::string subject)` using initializer list, and a method `getTeacherInfo()` that **returns** a `std::string` with both values
- Create a class called `Classroom` with private variables `std::string roomNumber`, `int capacity`, and a `Teacher` object — use composition, **not inheritance**
- Add a constructor `Classroom(std::string roomNumber, int capacity, Teacher teacher)` using initializer list
- Add a method `getClassroomInfo()` that **returns** a `std::string` containing room number, capacity, and teacher info by calling `getTeacherInfo()` internally — use `std::to_string()` for capacity
- Create a class called `School` with private variables `std::string schoolName` and a `std::vector<Classroom>` called `classrooms`
- Add a constructor `School(std::string schoolName)` and a method `addClassroom(Classroom classroom)` that pushes classrooms into the vector using `classrooms.push_back(classroom)`
- Add a method `getSchoolReport()` that **returns** a `std::string` containing school name and info of all classrooms by looping through the vector and calling `getClassroomInfo()` on each
- In the `main` function, create two `Teacher` objects, two `Classroom` objects, one `School` object, add both classrooms to the school, and print `getSchoolReport()`

---

## Question 10 — Putting It All Together

You are building a mini e-commerce order processing system.

- Create an abstract class called `Product` with private variables `std::string productId`, `std::string productName`, and `double basePrice`, a constructor that sets all values using initializer list and increments a static `int totalProducts`, getter methods `getProductId()`, `getProductName()`, `getBasePrice()` that **return** their values, a static method `getTotalProducts()` that returns the count, a **pure virtual** method `getFinalPrice()` that returns a `double`, and a `virtual` destructor
- Create a pure abstract class called `Discountable` with a pure virtual method `applyDiscount(double percentage)` that returns a `double`, and a virtual destructor
- Create a pure abstract class called `Taxable` with a pure virtual method `applyTax(double taxRate)` that returns a `double`, and a virtual destructor
- Create a class called `ElectronicProduct` that inherits from `Product`, `Discountable`, and `Taxable` with an additional private variable `std::string brand` — `getFinalPrice()` returns `getBasePrice() + applyTax(0.18)`, `applyDiscount()` returns `getBasePrice() - (getBasePrice() * percentage / 100)`, `applyTax()` returns `getBasePrice() * taxRate`
- Create a class called `ClothingProduct` that inherits from `Product` and `Discountable` with an additional private variable `std::string size` — `getFinalPrice()` returns `getBasePrice() - applyDiscount(10)`, `applyDiscount()` returns `getBasePrice() * percentage / 100`
- Create a class called `Order` with private variables `std::string orderId`, a `Product*` pointer inside it using composition, and a static `int totalOrders` that increments in the constructor
- Add a method `getOrderSummary()` that **returns** a `std::string` containing order id, product name, and final price by calling `getFinalPrice()` on the product pointer
- Initialize all static members outside the class
- In the `main` function, create one `ElectronicProduct` and one `ClothingProduct`, wrap each in an `Order` using pointers, print `getOrderSummary()` for each order, and print `Product::getTotalProducts()` and `Order::totalOrders`
