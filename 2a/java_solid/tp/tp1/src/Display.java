import java.util.List;

public class Display {

    Display(){};

    public static void menu(){
        System.out.println("MENU");
        System.out.println("-----------------------");
        System.out.println("1 : Add Patient");
        System.out.println("2 : Display all Patient");
        System.out.println("Anything : Stop Program");
        System.out.println("-----------------------");
        System.out.println("Your Choice: ");
    }

    public static void patientheque(List<Patient> p){
        for (Patient patient: p){
            System.out.println(patient);
        }
    }
}
