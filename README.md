# Intern Management System

A console-based C++ application that connects university students with company recruiters. It lets a student maintain an academic and skill profile, lets a university administrator manage students and courses, and lets a recruiter search those students against a set of criteria and mark the matching ones as selected.

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C)
![Standard](https://img.shields.io/badge/standard-C%2B%2B11-00599C)
![Build](https://img.shields.io/badge/build-g%2B%2B%20%2F%20TDM--GCC%209.2.0-00599C)
![License](https://img.shields.io/badge/license-MIT-green)

---

## 📌 Overview

Finding an internship usually means scattering across job boards, sending the same CV everywhere, and hoping someone reads it. Recruiters face the mirror-image problem: they know exactly the CGPA, skill set and city they want, but have no quick way to find students who actually match.

This project was written as an OOP (Object-Oriented Programming) coursework project to model that matching problem in code. It replaces the "post a listing and wait" loop with a searchable student pool:

- **Students** register their academic record (enrollment number, year, CGPA), a list of skills, registered courses and their location.
- **Admins** maintain the university's student and course records.
- **Recruiters** register universities, search the student pool, filter it by CGPA / skill / city, and mark students who satisfy all criteria as `SELECTED`.

The student can then check their own selection status.

> **Note on scope:** this is an academic OOP project focused on C++ language features and class design. It is a terminal application with no database, so all data lives in memory for the duration of the run. See [Limitations](#-limitations).

---

## ✨ Features

### Student

- Register personal details, enrollment number, enrollment year and CGPA
- Add and list skills; internal skill lookup used by recruiter filters
- Register courses and check whether a specific course is on record
- Update the complete profile in one step
- View full profile summary
- View saved address / district / state / city
- Check own selection status (`PENDING` or `SELECTED`)

### Admin (authenticated)

- Add and remove student records by enrollment number
- Add and remove courses by name
- Display all students, all courses, or the full university record
- Search inside the university by:
  - student name
  - enrollment number
  - CGPA
  - course name

### Recruiter (authenticated)

- Add and delete universities from the company, with their location
- Browse available universities and students
- Search across the company by:
  - student name
  - enrollment number
  - course name
  - university name
  - minimum CGPA
- Run criteria filters for:
  - minimum CGPA
  - required skill
  - city
- Send approval: a student is marked `SELECTED` only if they match **all** of skill, city, CGPA and course at once

### Cross-cutting

- Username + password login for the admin and recruiter roles
- Custom exception types for validation:
  - `User::PasswordException` — password must be exactly 4 characters
  - `Student::InvalidCgpaException` — CGPA cannot be negative

---

## 🛠️ Technologies Used

| Technology | Purpose |
| ---------- | ------- |
| C++ (C++11) | Implementation language |
| C++ Standard Library (`<iostream>`, `<string>`) | Console I/O and text handling |
| `new[]` / `delete[]` dynamic arrays | In-memory storage for students, courses, skills and universities |
| Header-only classes | All 9 classes are implemented entirely in `.h` files, included from `main.cpp` |
| GDB (MinGW-w64) | Debugging through the VS Code C/C++ extension |
| Embarcadero Dev-C++ 6.3 (TDM-GCC 9.2.0) | IDE the project was originally built in |
| GNU Make (`Makefile.win`) | Optional build automation for the Dev-C++ toolchain |
| PlantUML | Used in `readmeIMS.txt` for the class-design sketch |

There are **no third-party libraries and no external dependencies.** Only a C++ compiler is required.

---

## 🏗️ Project Structure

```text
.
├── main.cpp                 # Entry point: welcome banner, top-level menu, role dispatch
├── User.h                   # Abstract base class - credentials, pure virtual display()/login()
├── Student.h                # Student : User  - academic record, skills, courses, status
├── Admin.h                  # Admin : User    - university record management menu
├── Recruiter.h              # Recruiter : User - company-side search and selection menu
├── University.h             # Owns arrays of students and courses, provides search helpers
├── Company.h                # Owns arrays of universities, students, courses; criteria + approval
├── Course.h                 # Course name + acronym value class
├── Location.h               # Address, district, state, city value class
│
├── Int_pro.dev              # Dev-C++ project file (lists all 9 translation units)
├── Int_pro.layout           # Dev-C++ editor layout state (git-ignored)
├── Makefile.win             # Dev-C++ generated makefile (git-ignored, machine-specific paths)
│
├── readmeIMS.txt            # PlantUML class-design sketch of an extended version of the system
├── aieng.txt                # Personal notes, unrelated to the application
├── OOP_PROJECT_MNA_BS_AI_2530087.docx
│                            # Original coursework submission document (source listing)
│
├── docs/
│   └── architecture.md      # Class hierarchy, design decisions, OOP concepts used
├── screenshots/             # Console screenshots (empty - see Screenshots section)
│
├── .vscode/                 # Editor configuration for the C/C++ Runner extension
│
└── outputs/                 # Separate standalone mini-project (see note below)
    ├── gpaCalculator.cpp    # "Air University GPA Calculator" - has its own main()
    └── gpa.h                # gpa class used by the calculator
```

### Folder notes

- **Root `.h` files** — every class in the system. They are header-only by design so the whole program is a single translation unit.
- **`docs/architecture.md`** — the class hierarchy diagram and an explanation of which OOP concept is used where.
- **`readmeIMS.txt`** — an *early design sketch* of a much larger version of the system (vacancies, applications, interviews, resumes, reports, a `DatabaseManager`). Most of those classes were never implemented. It is kept as a record of the original design thinking, not as documentation of current behaviour.
- **`outputs/`** — a different, unrelated program (a GPA calculator) that ships alongside this project. It has its own `main()` and is not compiled into `Int_pro.exe`. If you want a focused repository, this folder can be moved to its own repository.

---

## ⚙️ Installation

There is nothing to install. The project has no package manager, no dependency manifest and no build system to bootstrap.

All you need is a C++ compiler.

### Option A — any GCC / MinGW compiler (recommended, portable)

Verified working with **g++ 9.2.0 (TDM-GCC, MinGW-w64)**.

```bash
g++ -std=c++11 -o Int_pro main.cpp
```

On Windows, if `g++` is not on your `PATH`, either add your compiler's `bin` folder to `PATH`, or call it by full path:

```bash
"C:\Program Files (x86)\Embarcadero\Dev-Cpp\TDM-GCC-64\bin\g++.exe" -std=c++11 -o Int_pro.exe main.cpp
```

On Linux / macOS:

```bash
g++ -std=c++11 -o Int_pro main.cpp
./Int_pro
```

### Option B — Embarcadero Dev-C++ (the original IDE)

1. Install Dev-C++ 6.3 (or any recent version).
2. Open `Int_pro.dev`.
3. Press **F11** to compile and run, or **F9** to compile only.

`Int_pro.dev` already registers all nine units (`main.cpp`, `User.h`, `Student.h`, `Admin.h`, `Recruiter.h`, `University.h`, `Company.h`, `Course.h`, `Location.h`), so no manual file adding is needed.

### Option C — VS Code

The repository includes a `.vscode/c_cpp_properties.json` configured for `windows-gcc-x64`. Install the **C/C++** extension (ms-vscode.cpptools), make sure `gcc`/`g++` is reachable, then use the integrated terminal:

```bash
g++ -std=c++11 -g -o Int_pro.exe main.cpp
```

### Clean

```bash
rm -f Int_pro Int_pro.exe main.o *.gch
```

Or, from a Dev-C++ command line using the included makefile:

```bash
mingw32-make -f Makefile.win clean
```

> `Makefile.win` hardcodes `C:/Program Files (x86)/Embarcadero/Dev-Cpp/TDM-GCC-64/...` include and library paths, so it only works on a machine with Dev-C++ installed at that exact location. The single `g++` command in Option A works everywhere.

---

## ▶️ How to Run

Build first (see [Installation](#%EF%B8%8F-installation)), then execute the binary.

```bash
# Windows
Int_pro.exe

# Linux / macOS
./Int_pro
```

The program is fully interactive and reads from stdin. Sample session:

```text
              WELCOME TO INTERNEE MANAGEMENT SYSTEM
            A COMPANY AT YOUR DOOR STEP TO PROVIDE YOU WITH GOLDEN OPPORTUNITIES

        ===INITIAL INTERFACE===
1. STUDENT LOGIN
2. ADMIN LOGIN
3. RECRUITER LOGIN
4. EXIT
Select one please:
```

### Pre-loaded demo accounts

Two accounts are created in `main.cpp` so the project can be explored immediately without a database:

| Role | Username | Password | Defined at |
| ---- | -------- | -------- | ---------- |
| Admin | `adm` | `1234` | `main.cpp:16` |
| Recruiter | `rec` | `1234` | `main.cpp:18` |

> These are hardcoded throwaway demo credentials, not real accounts. Because they live in source, anyone can read them — see [Limitations](#-limitations).

The **Student** menu (option 1 on the main screen) does not ask for credentials; it operates on a single `Student` object that the current run fills in.

### No configuration required

The project reads **no environment variables** and there is no `.env` file, so no `.env.example` is included. There is nothing to configure before running.

---

## 🗄️ Database

**This project does not use a database.**

All records are held in dynamic arrays owned by the `University` and `Company` objects, created with `new[]` at runtime and released in the destructors with `delete[]`. Because nothing is ever written to disk, **all data is lost when the program exits** — every run starts from an empty state.

The only persistent artefacts in the repository are compiled binaries (`.exe`, `.o`, `.gch`), which are git-ignored and rebuilt from source.

For context, the `DatabaseManager` class sketched in `readmeIMS.txt` shows that persistence was part of the original design intent, but it was never implemented.

---

## 📸 Screenshots

> **TODO — screenshots have not been added yet.**
> The `screenshots/` folder is currently empty (it only contains `.gitkeep` so the folder is tracked by git).
>
> To complete this section, capture the following console windows and save them into `screenshots/`:
>
> | Suggested file | What to capture |
> | -------------- | --------------- |
> | `01-main-menu.png` | The welcome banner and initial interface |
> | `02-student-profile.png` | Student menu → Enter Details, then Full Display |
> | `03-admin-menu.png` | Admin login and the admin menu |
> | `04-admin-search.png` | Admin → Search In University results |
> | `05-recruiter-criteria.png` | Recruiter → Set Criteria filters |
> | `06-selection-status.png` | Student menu → Check Status after approval |
>
> Then reference them in this section, for example:
>
> ```markdown
> ### Main interface
> ![Main interface](screenshots/01-main-menu.png)
> ```

---

## 🎯 Use Case

A realistic walkthrough of the system:

1. **Student registers a profile.** The student picks *Student Login* from the main menu and enters their name, a 4-character password, email, enrollment number, enrollment year, CGPA, a list of skills, and their location. A negative CGPA is rejected by `InvalidCgpaException`.

2. **Admin builds the university record.** The admin logs in with their credentials and adds students and courses to the university, then uses *Search In University* to look someone up by name, enrollment number, CGPA, or course name.

3. **Recruiter registers a university.** A recruiter logs in and adds the university to their company along with its location, and can delete it later if the partnership ends.

4. **Recruiter defines what they want.** Instead of a fixed vacancy form, the recruiter explores with the search menu — by name, enrollment number, course, university, or a minimum CGPA — and narrows the pool with the criteria filters for CGPA, a specific skill, and a city.

5. **Recruiter sends approval.** The recruiter enters the required skill, city, minimum CGPA and course. `Company::sendApproval()` evaluates all four conditions per student. Only students satisfying **every** condition are marked `SELECTED`; if nobody matches, it reports that.

6. **Student checks the outcome.** The student returns to *Check Status* and sees `SELECTED` instead of the default `PENDING`.

---

## 🚀 Future Improvements

The following are **not implemented** — they are ideas for extending the project.

- **File-based persistence** — serialise the `University` and `Company` records to CSV or JSON on exit and reload them on start, so data survives between sessions
- **A real database layer** — implement the `DatabaseManager` from the original design sketch and move all lookups to SQL
- **Proper authentication** — replace the hardcoded in-memory credentials with a stored user table and hashed passwords
- **Internship vacancies and applications** — model the `InternshipVacancy` / `InternshipApplication` / `Interview` classes that appear in `readmeIMS.txt` but were never built
- **Automated report generation** — export student, course and selection reports to a file
- **Email notifications** — notify students automatically when they are selected
- **Advanced analytics** — CGPA/skill distribution charts and a recruiter dashboard
- **Ranking and shortlisting** — score students against criteria instead of a binary match, and cap the number of selections per vacancy
- **Input hardening** — read multi-word fields with `getline` instead of `cin >>`, and validate all numeric input
- **Move GPA calculator to its own repository** — see the note on the `outputs/` folder

---

## ⚠️ Limitations

These are honest limitations of the current state of the code.

**Data and architecture**

- **No persistence.** Everything is in memory; closing the program deletes all records.
- **No database.** Search is a linear scan over dynamic arrays, which is fine for coursework but will not scale.
- **A single shared student instance.** The student menu operates on one `Student` object created in `main.cpp`, so only one student profile exists per run. The admin and recruiter menus operate on their own separate arrays, so a student added by the admin is not the same object the student menu edits.
- **The company starts empty.** `Company` is default-constructed, so `companyName` is blank and the company view prints an empty record until a recruiter adds a university.

**Correctness issues found in the code**

- `Company::addUniversity()` reads the student and course counts into `stcnt` and `crcnt` but then passes the **uninitialised** `stsize` and `crsize` to `setUniversity()`. It also calls `student[i].setStudentData()` in a loop over `stcnt` *before* the `student` array has been allocated, which dereferences a null pointer. This path needs fixing.
- `Company.h:88` contains a stray `\` character left over from editing. It happens to compile (the compiler treats it as a line continuation) but it is not valid, intentional code.
- `University::searchBYCGPAUNI()` prints `NOT FOUND` even after a successful match, and contains an empty `if (!found) { }` block.
- `User::password` is compared in plaintext and stored in plaintext.
- The student menu is reachable without logging in, even though `Student::login()` is implemented.

**Build and repository hygiene**

- `Makefile.win` and `Int_pro.dev` reference absolute Dev-C++ paths, so they are specific to one machine.
- `outputs/gpaCalculator.cpp` and `outputs/gpa.h` use `qualityPoints` without initialising it, so the first run returns a garbage GPA. Both also allocate a `subjects` array that is never used, and overwrite a single `name` variable per iteration instead of storing per-subject records.
- No automated tests and no CI are configured.
- Mixed tab and space indentation across the headers, inherited from the original editor.

**Documentation**

- `readmeIMS.txt` describes a substantially larger system than the one implemented. Reading it as a feature list would be misleading; it is a design sketch.

---

## 👨‍💻 Author

**Muhammad Nayyar Ameer**

Originally written as an Object-Oriented Programming coursework project (BS Artificial Intelligence).

- GitHub: `<add your GitHub profile URL here>`
- Email: `<add your email here>`
- LinkedIn: `<add your LinkedIn URL here>`

<!-- Replace the three placeholders above with your real profile links before publishing. -->

---

## 📄 License

Released under the **MIT License** — see [LICENSE](LICENSE).

MIT was chosen because the code is a self-contained coursework project with no third-party dependencies and no proprietary requirement from an employer or institution, and the MIT license is short, permissive and widely accepted in software portfolios. It allows anyone to use, modify and redistribute the code with attribution.

If you later add employer- or university-owned code, or want to prevent reuse, switch to a copyleft license such as GPL-3.0, or remove the `LICENSE` file to keep the repository proprietary.

---

## 📚 Further Reading

- [`docs/architecture.md`](docs/architecture.md) — class hierarchy, design decisions, and which OOP concept is used where
