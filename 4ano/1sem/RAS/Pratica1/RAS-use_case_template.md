# Use Case: [Title]

| **Section** | **Details** |
|-------------|-------------|
| **Use Case ID** | *Unique identifier, e.g., UC-001* |
| **Name** | *Short descriptive name of the use case* |
| **Version** | *Document version, e.g., v1.0* |
| **Author** | *Person who defined this use case* |
| **Date** | *Creation or last update date* |
| **Goal** | *What the actor wants to achieve by using the system* |
| **Scope** | *System/module/subsystem this use case belongs to* |
| **Primary Actor** | *Main actor initiating the use case (user or external system)* |
| **Stakeholders & Interests** | *List stakeholders and their goals/interests (e.g., user wants quick access, admin wants secure system)* |
| **Preconditions** | *What must be true before starting (e.g., user registered, system online)* |
| **Trigger** | *Event that initiates the use case (e.g., user clicks “Login”)* |

---

## Main Flow

| **Step** | **Actor Action** | **System Response** |
|----------|------------------|----------------------|
| 1 | *What the actor does first* | *How the system responds* |
| 2 | *Next actor action* | *System behavior* |
| 3 | ... | ... |

*→ This is the “happy path,” the ideal flow where everything works correctly.*

---

## Alternate Flows

| **Flow** | **Description** |
|----------|------------------|
| AF1 – [Name] | *Variation from the main flow (e.g., login with Google)* |
| AF2 – [Name] | *Another variation (e.g., “Remember Me” option)* |

*→ Covers optional flows or variations where the goal is still achieved.*

---

## Exceptions

| **Condition** | **System Behavior** |
|---------------|----------------------|
| *Error condition (e.g., wrong password)* | *How the system handles it (show error, retry, etc.)* |
| *Another error/issue* | *System handling* |

*→ Defines what happens when things go wrong (errors, failures, unavailability).*

---

## Postconditions

| **Type** | **Outcome** |
|----------|-------------|
| Success Guarantee | *System state if the use case is successful* |
| Minimal Guarantee | *System state if the use case fails or is aborted* |

---

## Business Rules & Constraints

| **Rule** |
|----------|
| *Policy, constraint, or rule that applies (e.g., password complexity)* |
| *Another applicable rule* |

---

## Assumptions

| **Assumption** |
|----------------|
| *Something assumed to be true (e.g., internet is available)* |
| *Another assumption* |

---

## Open Issues

| **Question** |
|--------------|
| *Unresolved question or decision to be made (e.g., Should MFA be included?)* |
| *Another open question* |