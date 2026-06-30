# # # # #     class Employee:
# # # # #     def __init__(self, emp_id, name, basic_salary):
# # # # #         self.emp_id = emp_id
# # # # #         self.name = name
# # # # #         self.basic_salary = basic_salary
# # # # #     def calculate_salary(self):
# # # # #         return self.basic_salary
# # # # # class FullTimeEmployee(Employee):
# # # # #     def __init__(self, emp_id, name, basic_salary, hra, da):
# # # # #         super().__init__(emp_id, name, basic_salary)
# # # # #         self.hra = hra
# # # # #         self.da = da

# # # # #     def calculate_salary(self):
# # # # #         return self.basic_salary + self.hra + self.da
# # # # # class PartTimeEmployee(Employee):
# # # # #     def __init__(self, emp_id, name, hours_worked, rate_per_hour):
# # # # #         super().__init__(emp_id, name, 0)
# # # # #         self.hours_worked = hours_worked
# # # # #         self.rate_per_hour = rate_per_hour

# # # # #     def calculate_salary(self):
# # # # #         return self.hours_worked * self.rate_per_hour
# # # # # # Execution
# # # # # fte = FullTimeEmployee(1, "Amit", 20000, 5000, 3000)
# # # # # pte = PartTimeEmployee(2, "Neha", 40, 500)
# # # # # print("Full-Time Salary:", fte.calculate_salary())
# # # # # print("Part-Time Salary:", pte.calculate_salary())

# # # #  class Product:
# # # #     def __init__(self, product_id, name, price):
# # # #         if price < 0:
# # # #             raise ValueError("Price cannot be negative")
# # # #         self.product_id = product_id
# # # #         self.name = name
# # # #         self.price = price
# # # # class Cart:
# # # #     def __init__(self):
# # # #         self.products = []

# # # #     def add_product(self, product):
# # # #         self.products.append(product)

# # # #     def remove_product(self, product_id):
# # # #         self.products = [p for p in self.products if p.product_id != product_id]

# # # #     def calculate_total(self):
# # # #         return sum(p.price for p in self.products)
# # # # # Execution
# # # # cart = Cart()
# # # # cart.add_product(Product(1, "Laptop", 50000))
# # # # cart.add_product(Product(2, "Mouse", 500))
# # # # print("Total Amount:", cart.calculate_total())
# # # class BankAccount:
# # #     def __init__(self):
# # #         self.__balance = 0
# # #         self.transactions = []
# # #     def deposit(self, amount):
# # #         if amount > 0:
# # #             self.__balance += amount
# # #             self.transactions.append(f"Deposited {amount}")
# # #     def withdraw(self, amount):
# # #         if amount <= self.__balance:
# # #             self.__balance -= amount
# # #             self.transactions.append(f"Withdrawn {amount}")
# # #         else:
# # #             print("Insufficient Balance")
# # #     def get_transaction_history(self):
# # #         return self.transactions
# # # # Execution
# # # acc = BankAccount()
# # # acc.deposit(5000)
# # # acc.withdraw(2000)
# # # acc.withdraw(4000)
# # # print(acc.get_transaction_history())
# # class Student:
# #     def __init__(self, student_id, name):
# #         self.student_id = student_id
# #         self.name = name
# # class Course:
# #     def __init__(self, course_id, course_name, max_students):
# #         self.course_id = course_id
# #         self.course_name = course_name
# #         self.max_students = max_students
# #         self.enrolled_students = []
# #     def enroll_student(self, student):
# #         if len(self.enrolled_students) < self.max_students:
# #             self.enrolled_students.append(student)
# #         else:
# #             print("Seats Full")
# #     def display_students(self):
# #         for s in self.enrolled_students:
# #             print(s.name)
# # # Execution
# # course = Course(101, "Python", 2)
# # course.enroll_student(Student(1, "Amit"))
# # course.enroll_student(Student(2, "Neha"))
# # course.enroll_student(Student(3, "Rahul"))
# # course.display_students()
# class Logger:
#     def log(self, message):
#         pass
# class ConsoleLogger(Logger):
#     def log(self, message):
#         print("Console Log:", message)
# class FileLogger(Logger):
#     def log(self, message):
#         with open("log.txt", "a") as file:
#             file.write(message + "\n")
# def log_message(logger):
#     logger.log("System Started")
# # Execution
# log_message(ConsoleLogger())
# log_message(FileLogger())
from abc import ABC, abstractmethod
class Vehicle(ABC):
    def __init__(self, vehicle_id, brand, rate_per_day):
        self.vehicle_id = vehicle_id
        self.brand = brand
        self.rate_per_day = rate_per_day
    @abstractmethod
    def calculate_rent(self, days):
        pass
    def get_details(self):
        return f"{self.brand} - {self.vehicle_id}"
class Car(Vehicle):
    def __init__(self, vehicle_id, brand, rate_per_day, car_type):
        super().__init__(vehicle_id, brand, rate_per_day)
        self.car_type = car_type

    def calculate_rent(self, days):
        return self.rate_per_day * days
class Bike(Vehicle):
    def __init__(self, vehicle_id, brand, rate_per_day, engine_capacity):
        super().__init__(vehicle_id, brand, rate_per_day)
        self.engine_capacity = engine_capacity

    def calculate_rent(self, days):
        return self.rate_per_day * days * 0.9
class RentalService:
    def __init__(self):
        self.available = []
        self.rented = []
    def add_vehicle(self, vehicle):
        self.available.append(vehicle)
    def rent_vehicle(self, vehicle_id, days):
        for v in self.available:
            if v.vehicle_id == vehicle_id and days > 0:
                self.available.remove(v)
                self.rented.append(v)
                print("Vehicle rented successfully!")
                print("Total Rent:", v.calculate_rent(days))
                return
        print("Vehicle not available")
    def display_available_vehicles(self):
        for v in self.available:
            print(v.get_details())
# Execution
service = RentalService()
bike = Bike(1, "Honda", 500, 150)
service.add_vehicle(bike)
service.rent_vehicle(1, 10)
service.display_available_vehicles()





