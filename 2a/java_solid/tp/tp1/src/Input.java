import java.util.Scanner;

public class Input {

    Input(){};

    public static Patient saisirPatient(){
        Scanner scF = new Scanner(System.in);
        System.out.println("Patient firstname: ");
        String firstName = scF.nextLine();
        Scanner scL = new Scanner(System.in);
        System.out.println("Patient lastname: ");
        String lastName = scL.nextLine();

        return new Patient(lastName, firstName);
    }

    public static int saisirMenu(){
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
}
