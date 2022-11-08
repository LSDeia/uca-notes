import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Patientheque patientheque = new Patientheque();
        boolean loop = true;

        while(loop) {

            Display.menu();
            int res = Input.saisirMenu();

            switch (res) {
                case 1:
                    Patient haha = Input.saisirPatient();
                    patientheque.add(haha);
                    break;
                case 2:
                    Display.patientheque(patientheque.patientList);
                    break;
                default:
                    System.out.println("End of Program");
                    return;
            }
        }
    }
}