package metaplayback;

import java.io.File;

import aterm.*;

public class FileElement {
	private String fileName;
	private String filePath;
	private String fileType;
	private File file;
	private ATermFactory factory;
	
	public FileElement(ATerm fileTerm, ATermFactory factory, String filePath){
		this.factory = factory;
		fileType = fileTerm.getChildAt(0).toString();
		fileType = fileType.substring(1, fileType.length()-1);
		fileName = fileTerm.getChildAt(1).toString();
		fileName = fileName.substring(1, fileName.length()-1);
		if(fileType.equals("executeMap")){
			file = new File(fileName);
			this.filePath = file.toString();
		}
		else{
			this.filePath = filePath;
			file = new File(filePath + "/" + fileName);
		}
	}
	public FileElement(ATerm fileTerm, ATermFactory factory, String filePath, String fileMap){
		this.factory = factory;
		fileType = fileTerm.getChildAt(0).toString();
		fileType = fileType.substring(1, fileType.length()-1);
		fileName = fileTerm.getChildAt(1).toString();
		fileName = fileName.substring(1, fileName.length()-1);
		if(fileType.equals("executeMap")){
			file = new File(fileName);
			this.filePath = file.toString();
		}
		else{
			this.filePath = filePath + "/" + fileMap;
			file = new File(this.filePath + "/" + fileName);
		}
	}
	public String getFileName(){
		return fileName;
	}
	public String getFileType(){
		return fileType;
	}
	public boolean fileExist(){
		boolean returnValue = false;
		returnValue =  file.exists();
		return returnValue;
	}
	public File getFile(){
		return file;
	}
}
