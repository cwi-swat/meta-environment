public class AddressBookEntry implements IAddressBookEntry {
  private String name;
  public void setName(String name) { this.name = name; }
  public String getName() { return name; }

  private String address;
  public void setAddress(String address) { this.address = address; }
  public String getAddress() { return address; }

  public String toString() {
    return "entry[name="  +getName() + ",address=" + getAddress() + "]";
  }
}
