public class Patient {
    String firstName;
    String lastName;

    Patient(String lastName, String firstName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    @Override
    public String toString(){
        return this.lastName + ' ' + this.firstName;
    }
}