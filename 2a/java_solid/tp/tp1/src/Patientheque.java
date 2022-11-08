import java.util.ArrayList;
import java.util.List;

public class Patientheque {

    List<Patient> patientList;

    Patientheque(){
        this.patientList = new ArrayList<Patient>();
    }

    public void add (Patient patient){
        this.patientList.add(patient);
    }
}
