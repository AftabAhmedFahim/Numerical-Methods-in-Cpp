# 📘 Numerical Methods in C++

This repository contains C++ implementations of classical numerical methods, organized into categories such as **Root Finding, Interpolation, Regression, Error Analysis, and Utilities**.  
The goal is to provide clean, well-documented implementations for learning and reference.

---

## 📂 Directory Structure

- **src/**
  - **[root_finding/](src/root_finding/)** - Root-finding algorithms
    - **[bisection_iterative.cpp](src/root_finding/bisection_iterative.cpp)**
    - **[bisection_tolerance.cpp](src/root_finding/bisection_tolerance.cpp)**
    - **[false_position.cpp](src/root_finding/false_position.cpp)**
    - **[secant.cpp](src/root_finding/secant.cpp)**
    - **[fixed_point.cpp](src/root_finding/fixed_point.cpp)**
    - **[newton_raphson.cpp](src/root_finding/newton_raphson.cpp)**
    - **[modified_newton.cpp](src/root_finding/modified_newton.cpp)**
    - **[modified_bisection.cpp](src/root_finding/modified_bisection.cpp)**
  
  - **[interpolation/](src/interpolation/)** - Interpolation techniques
    - **[lagrange.cpp](src/interpolation/lagrange.cpp)**
    - **[newton_divided.cpp](src/interpolation/newton_divided.cpp)**
  
  - **[regression/](src/regression/)** - Regression & curve fitting
    - **[linear_regression.cpp](src/regression/linear_regression.cpp)**
    - **[polynomial_regression.cpp](src/regression/polynomial_regression.cpp)**
    - **[curve_fitting.cpp](src/regression/curve_fitting.cpp)**
    - **[correlation_coefficients.cpp](src/regression/correlation_coefficients.cpp)**
  
  - **[error_analysis/](src/error_analysis/)** - Error calculation
    - **[mse_rmse.cpp](src/error_analysis/mse_rmse.cpp)**
  
  - **[utilities/](src/utilities/)** - Helper functions
    - **[horners_rule.cpp](src/utilities/horners_rule.cpp)**

- **[.gitignore](.gitignore)**
- **[LICENSE](LICENSE)**
- **[README.md](README.md)**

---

## 📌 Implemented Methods

### 🔹 Root Finding
- **[Bisection Method](src/root_finding/)** (Iterative & Error Tolerance)
- **[False Position Method](src/root_finding/false_position.cpp)**
- **[Secant Method](src/root_finding/secant.cpp)**
- **[Fixed Point Iteration](src/root_finding/fixed_point.cpp)**
- **[Newton-Raphson Method](src/root_finding/newton_raphson.cpp)**
- **[Modified Newton-Raphson](src/root_finding/modified_newton.cpp)**
- **[Modified Bisection](src/root_finding/modified_bisection.cpp)**

### 🔹 Interpolation
- **[Lagrange Interpolation](src/interpolation/lagrange.cpp)**
- **[Newton Divided Difference Interpolation](src/interpolation/newton_divided.cpp)**

### 🔹 Regression & Curve Fitting
- **[Linear Regression](src/regression/linear_regression.cpp)**
- **[Polynomial Regression](src/regression/polynomial_regression.cpp)**
- **[General Curve Fitting](src/regression/curve_fitting.cpp)**
- **[Correlation Coefficients](src/regression/correlation_coefficients.cpp)**

### 🔹 Error Analysis
- **[Mean Square Error (MSE)](src/error_analysis/mse_rmse.cpp)**
- **[Root Mean Square Error (RMSE)](src/error_analysis/mse_rmse.cpp)**

### 🔹 Utilities
- **[Horner's Rule](src/utilities/horners_rule.cpp)** (Efficient polynomial evaluation)

---

## 🛠 Requirements

- C++ Compiler (e.g., g++, clang++, MSVC)
- Basic knowledge of numerical methods

---

## 📜 License

This project is licensed under the MIT License - see the **[LICENSE](LICENSE)** file for details.

---

## ✨ Author

Developed by **Aftab Ahmed Fahim**
