# Exercise 2: From System Requirements to a System Requirements Specification

## 🎯 Objective
Extend the system requirements derived in **Exercise 1 (UC-001: User Login)** to produce a **complete System Requirements Specification (SRS)**.  
You will elaborate both **functional** and **non-functional** system requirements and **categorize** the non-functional ones according to standard quality characteristics (e.g., following Robertson and Robertson (2006)).

---

## 📘 Context
In **Exercise 1**, you identified **System Requirements Derived from UC-001 (User Login)**.  
Now, you will refine those requirements and create a more formal and complete **System Requirements Specification (SRS)** section.

---

## 🧠 Tasks

1. **Review your results from Exercise 1.**  
   Identify which requirements are **functional** (describe *what* the system shall do).

2. **Add non-functional requirements.**  
   Define *how well* the system shall perform its functions, focusing on aspects such as:
   - Performance (e.g., response time, scalability)
   - Security (e.g., authentication, password management)
   - Usability (e.g., error messages, accessibility)
   - Reliability (e.g., availability, error recovery)
   - Maintainability (e.g., modular design, configurability)

3. **Classify each non-functional requirement** according to its **quality characteristic**, following Robertson and Robertson (2006):

   1. appearance: the visual aspect and the aesthetics of the system, namely the graphical interface;
   2. usability: the easiness of utilisation of the system and everything that permits a more friendly user experience;
   3. performance efficiency: aspects of speed, real-time, storage capacity, and execution correction;
   4. operational: characteristics about what the system must do to work correctly in the environment where it is inserted;
   5. maintenance and support: attributes that allow the system to be repaired or improved and new functionalities to be anticipated;
   6. security: issues related to access, confidentiality, protection, and integrity of the data;
   7. cultural and political: factors related to the stakeholders culture and habits;
   8. legal: laws, rules, and standards that apply to the system so that it can operate.

4. **Write your requirements in a consistent and verifiable way**, using a clear and testable format:  

    The system shall *[action or behavior]* *[object or target]* *[performance condition or constraint]*.

5. **Structure your SRS section** in the following format:

---

## 📝 System Requirements Specification (SRS) — UC-001: User Login

### 1. Functional Requirements

| ID | Requirement Description | Rationale | Acceptance Criteria |
|----|--------------------------|------------|----------------------|
| FR-001 | The system shall allow users to log in using a valid username and password. | Core authentication mechanism. | The system verifies credentials and grants access. |
| FR-002 | The system shall display an error message when login credentials are invalid. | Improve user feedback. | The message describes the type of error occurred.
| FR-003 | The system shall lock the account after 5 failed login attempts. | Prevent brute-force attacks. | Account locked and notification sent. |

---

### 2. Non-Functional Requirements

| ID | Requirement Description | Quality Characteristic | Rationale | Acceptance Criteria |
|----|--------------------------|------------------------|------------|----------------------|
| NFR-001 | The login process shall complete within 2 seconds under normal load. | Performance Efficiency | Ensures responsiveness. | Tested under 100 concurrent users. |
| NFR-002 | Passwords shall be stored using salted hash encryption. | Security | Prevents unauthorized access to stored credentials. | Verified via security audit. |
| NFR-003 | The login screen shall be accessible on mobile and desktop devices. | Usability / Portability | Provides consistent user experience. | Responsive design validated on 3 major browsers. |
| NFR-004 | The system shall recover automatically after a failed authentication service call. | Reliability | Ensures service continuity. | Recovery verified during system testing. |
| NFR-005 | The login module shall be configurable without code modification. | Maintainability | Simplifies system updates. | Configuration verified through admin interface. |

---

## ✅ Expected Output
By the end of this exercise, you should have:
- A well-structured **System Requirements Specification (SRS)** section.  
- A clear distinction between **functional** and **non-functional** requirements.  
- Proper **classification of non-functional requirements** based on ISO/IEC 25010 quality attributes.

---

## 📊 Evaluation Criteria

| Criterion | Description |
|------------|--------------|
| Completeness | All relevant functional and non-functional requirements are covered. |
| Clarity | Requirements are unambiguous and testable. |
| Traceability | Requirements can be linked to the original Use Case (UC-001). |
| Correct Classification | Non-functional requirements are correctly categorized. |

---