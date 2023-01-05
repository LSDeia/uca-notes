package com.example.demo1;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;

import java.net.URL;
import java.util.ResourceBundle;

public class MyController implements Initializable {
    @FXML
    private Spinner<Integer> mySpinner;

    @FXML
    private Label myLabel;

    int currentValue = 9;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle)
    {
        SpinnerValueFactory<Integer> valueFactory =
                new SpinnerValueFactory.IntegerSpinnerValueFactory(-10, 40);
        valueFactory.setValue(0);
        currentValue = mySpinner.getValue();
        myLabel.setText(Integer.toString(currentValue));
        mySpinner.setValueFactory(valueFactory);
        mySpinner.valueProperty().addListener(new ChangeListener<Integer>()
        {
            @Override
            public void changed(ObservableValue<? extends Integer> arg0, Integer arg1, Integer arg2)
            {
                currentValue = mySpinner.getValue();
                myLabel.setText(Integer.toString(currentValue));
            }
        });
    }
}
