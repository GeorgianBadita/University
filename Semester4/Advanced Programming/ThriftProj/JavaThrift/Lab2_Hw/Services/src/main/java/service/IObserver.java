package service;

import java.rmi.RemoteException;

public interface IObserver {
    void updateSeats() throws RemoteException;
}
