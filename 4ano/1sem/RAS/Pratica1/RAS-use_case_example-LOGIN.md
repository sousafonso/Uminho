

# Use Case: User Login

| **Section** | **Details** |
|-------------|-------------|
| **Use Case ID** | UC-001 |
| **Name** | User Login |
| **Version** | v1.0 |
| **Author** | Andre Ferreira |
| **Date** | 2025-09-29 |
| **Goal** | Allow registered users to securely log in and access the application. |
| **Scope** | Authentication module |
| **Primary Actor** | Registered User |
| **Stakeholders & Interests** | - **User**: wants quick, secure access<br>- **System Owner**: restricts access to authorized users<br>- **Security Team**: ensures logging and monitoring of login attempts |
| **Preconditions** | - User must be registered<br>- Login page available |
| **Trigger** | User opens the login page and enters credentials |

---

## Main Flow

| **Step** | **Actor Action** | **System Response** |
|----------|------------------|----------------------|
| 1 | User navigates to login page | Displays login form |
| 2 | User enters username/email and password | — |
| 3 | User clicks **Login** | System validates credentials |
| 4 | — | If valid, create authenticated session |
| 5 | — | Redirect user to dashboard/homepage |

---

## Alternate Flows

| **Flow** | **Description** |
|----------|------------------|
| AF1 – Remember Me | User checks “Remember Me” → System creates persistent login token |
| AF2 – Social Login | User selects “Login with Google” → OAuth authentication → If successful, system logs user in |

---

## Exceptions

| **Condition** | **System Behavior** |
|---------------|----------------------|
| Invalid credentials | Show error: *“Invalid username or password”* |
| Multiple failed attempts | Lock account → Prompt user to reset password or contact support |
| Server unavailable | Show error: *“Login service temporarily unavailable”* |

---

## Postconditions

| **Type** | **Outcome** |
|----------|-------------|
| Success Guarantee | User logged in, valid session created, redirected to dashboard |
| Minimal Guarantee | User remains logged out, no session created |

---

## Business Rules & Constraints

| **Rule** |
|----------|
| Password must meet complexity requirements (≥ 8 chars, 1 uppercase, 1 digit, 1 symbol) |
| System locks account after 5 failed attempts within 10 min |
| Session timeout after 30 min of inactivity |

---

## Assumptions

| **Assumption** |
|----------------|
| Users have stable internet connection |
| Authentication database is online and up to date |

---

## Open Issues

| **Question** |
|--------------|
| Should MFA (Multi-Factor Authentication) be supported in v1? |
| Should “Remember Me” use cookies or secure tokens? |