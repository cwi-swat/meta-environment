//package casestudy.rmi;

import java.rmi.*;

public interface AddressBook extends Remote {
  public void add(String name, String address) throws RemoteException;
  public void remove(String name) throws RemoteException;
  public String getAddress(String name) throws RemoteException;
}
