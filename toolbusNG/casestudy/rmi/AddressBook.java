package casestudy.rmi;

import java.rmi.*;

public interface AddressBook extends Remote {
  public void add(String name, Address address) throws RemoteException;
  public void remove(String name) throws RemoteException;
  public Address getAddress(String name) throws RemoteException;
}
