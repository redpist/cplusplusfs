c++sh examples
==============


```c++

File current_directory("."); // == pwd

for (auto file: File(".").Files()) { // == ls
  printf("%s ", file.Name().c_str());
}
printf("\n");


File(".").CreateFile();


```
