use std::fs;
use std::io::{Error, ErrorKind};
use std::path::Path;
use std::process::Command;

pub fn run(args: Vec<&str>) -> std::io::Result<()> {
    let debug = ".\\build\\debug\\debug.exe";
    let release = ".\\build\\release\\release.exe";

    if Path::new(debug).exists() && !Path::new(release).exists() {
        Command::new(debug).args(args).status().expect("Cannot run binary");
        fs::remove_file(debug)?;
        Ok(())
    } else if Path::new(release).exists() && !Path::new(debug).exists() {
        Command::new(release).args(args).status().expect("Cannot read binary");
        fs::remove_file(release)?;
        Ok(())
    } else {
        Err(Error::new(ErrorKind::Other, "Cannot find binary"))
    }
}
