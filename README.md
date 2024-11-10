#<ins>Project Overview</ins>
My project is a student database management system built in C language with file-based data storage. It uses a struct/structure-based approach for data organization, allowing operations like adding, editing, deleting, and searching student records efficiently.
#<ins>Features of the Project</ins>
##User Authentication:
The system implements an admin login feature using password masking for secure input. The password is masked during entry, ensuring sensitive data isn't displayed on the screen, enhancing data confidentiality.
##Data Persistence:
All student records are stored persistently using binary file operations (fopen, fread, fwrite), which ensures that the data remains intact even after the program exits. I used separate files for primary data (Data_file) and temporary data storage (Tmp_file) to facilitate record management during updates and deletions.
##CRUD Operations:
The project supports CRUD operations for student records. These operations include adding, updating, deleting, and searching for specific student data, which is managed efficiently using a series of file handling techniques and control structures.
##Error Handling and Input Validation:
Input validation is integrated to prevent invalid data entries (e.g., non-positive roll numbers), and error handling is included to manage cases such as missing files or incorrect roll numbers. This ensures that the system remains robust and prevents unexpected failures.
##Memory Management and Data Security:
The project utilizes memory-safe operations and clears sensitive information, like passwords, from memory after use to enhance security. Additionally, the memcpy function could be integrated to overwrite any residual sensitive data in memory.
##Scalability:
The use of binary files and efficient I/O operations allows the program to scale easily with the number of student records, making it adaptable for larger datasets without significantly affecting performance.
#<ins>Future Enhancements</ins>
##Transition to Database Management System (DBMS):
In the future, I plan to upgrade from file-based storage to a more robust relational database management system (RDBMS), such as MySQL or SQLite. This enhancement would improve data retrieval speed, enable complex querying capabilities, and provide better data consistency and security, especially for larger datasets.
##User Role Management and Access Control:
To enhance security, I could incorporate user role management by creating additional access levels. For example, adding roles like 'Admin', 'Teacher', and 'Student' would allow me to control access permissions, ensuring only authorized users can view or edit specific data.
##Data Encryption for Secure Storage:
As data security is essential, implementing encryption for sensitive information (e.g., passwords and student details) would further safeguard the system. This enhancement would involve integrating encryption algorithms like AES to protect data at rest.
