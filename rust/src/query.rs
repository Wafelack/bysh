use std::process::Command;
use std::str;

fn exists(lib_name: &str) -> bool {
    let output = Command::new("curl")
        .arg("https://wafelack.alwaysdata.net/libs.txt")
        .output()
        .unwrap();
    let out = match str::from_utf8(&output.stdout) {
        Ok(s) => s,
        Err(_e) => return false,
    };
    let libs: Vec<&str> = out.split('\n').collect();
    for l in libs {
        if l == lib_name {
            return true;
        }
    }
    false
}

pub fn query(lib: &str) {
    if exists(lib) {
        println!("Library `{}` exists !", lib);
    } else {
        println!("Library `{}` does not exists !", lib);
    }

}