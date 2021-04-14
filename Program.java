import java.util.*;
import java.util.stream.Collectors;
import java.util.function.Function;

class Employee{
    int id;
    String name;

    Employee(int id, String name){
        this.id = id;
        this.name = name;
    }

    int getId(){
        return this.id;
    }

    String getName(){
        return this.name;
    }

    public String toString(){
        StringBuilder s = new StringBuilder("Employee id : ").append(this.id).append(", name : ").append(this.name);
        return s.toString();
    }
}    
public class Program
{
    public static void main(String[] args) {
        Employee e1 = new Employee(1, "XXX");
        Employee e2 = new Employee(9, "PPP");
        Employee e3 = new Employee(13, "PPP");
        Employee e4 = new Employee(2, "XXX");
        Employee e5 = new Employee(8, "CCC");

        List<Employee> employees = new ArrayList<>();
        employees.add(e1);
        employees.add(e2);
        employees.add(e3);
        employees.add(e4);
        employees.add(e5);

        System.out.println(employees);
        Map<String, Long> resultE = employees.stream().collect(Collectors.groupingBy(Employee::getName, Collectors.counting()));
        System.out.println(resultE);
        

        List<String> names = Arrays.asList("AAA","BBB","BBB","AAA","CCC");
        Map<String, Long> result = names.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        System.out.println(result);
    }
}