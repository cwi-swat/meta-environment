import java.rmi.*;

public interface IAddressBookService extends Remote {
  public int create() throws RemoteException;
  public void delete(int id) throws RemoteException;
  public void setName(int id, String name) throws RemoteException;
  public void setAddress(int id, String address) throws RemoteException;
  public void setZip(int id, String zip) throws RemoteException;
}
