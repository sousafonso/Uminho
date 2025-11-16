## 📝 System Requirements Specification (SRS) — UC-001: Carregar Imagem

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
## 📝 System Requirements Specification (SRS) — UC-002: Carregar Imagem

### 1. Functional Requirements

| ID | Requirement Description | Rationale | Acceptance Criteria |
|----|--------------------------|------------|----------------------|
| FR-001 | O sistema deve permitir que o utilizador carregue uma imagem. | Core functionality for image upload. | The system accepts and processes the image file. |
| FR-002 | O sistema deve validar o formato da imagem antes do upload. | Ensure only supported formats are uploaded. | Formatos incorretos não são passíveis de seleção |
| FR-003 | O sistema deve exibir uma pré-visualização da imagem após o upload. | Improve user feedback and interaction. | The uploaded image is displayed for user confirmation. |

---

### 2. Non-Functional Requirements

| ID | Requirement Description | Quality Characteristic | Rationale | Acceptance Criteria |
|----|--------------------------|------------------------|------------|----------------------|
| NFR-001 | The login process shall complete within 2 seconds under normal load. | Performance Efficiency | Ensures responsiveness. | Tested under 100 concurrent users. |
| NFR-002 | Passwords shall be stored using salted hash encryption. | Security | Prevents unauthorized access to stored credentials. | Verified via security audit. |
| NFR-003 | The login screen shall be accessible on mobile and desktop devices. | Usability / Portability | Provides consistent user experience. | Responsive design validated on 3 major browsers. |
| NFR-004 | The system shall recover automatically after a failed authentication service call. | Reliability | Ensures service continuity. | Recovery verified during system testing. |
| NFR-005 | The login module shall be configurable without code modification. | Maintainability | Simplifies system updates. | Configuration verified through admin interface. |