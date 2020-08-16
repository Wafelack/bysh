/*
WANAGER API
*/
use std::process::Command;
use std::str;

pub struct Wanager;

impl Wanager {
    pub fn exists(self, lib_name: &str) -> bool {
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
    pub fn get_link(self, lib_name: &str) -> (&str, &str) {
        let header: &str = format!("https://wafelack.alwaysdata.net/{}.h", lib_name);
        let file: &str = format!("https://wafelack.alwaysdata.net/{}.c", lib_name);
        (header, file)
    }
}
