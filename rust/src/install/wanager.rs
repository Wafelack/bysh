use std::process::Command;
use std::str;

pub struct Wanager;

impl Wanager {
    pub fn exists(&self, lib_name: &str) -> bool {
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
    pub fn get_link(&self, lib_name: &str) -> (String, String) {
        let header: String = format!("https://wafelack.alwaysdata.net/{}.h", lib_name);
        let file: String = format!("https://wafelack.alwaysdata.net/{}.c", lib_name);
        (header, file)
    }
    pub fn install(&self, lib_name:&str,  link: (String, String)) -> std::io::Result<()> {
        let full_dir: String = format!("src\\{}", lib_name);
        match std::fs::create_dir(&full_dir) {
            Ok(_) => (),
            Err(e) => return Err(e),
        };

        let full_head: String = format!("{}/{}.h", &full_dir, lib_name);
        let full_file: String = format!("{}/{}.c", &full_dir, lib_name);

        Command::new("curl").arg(link.0).arg("-o").arg(full_head).status().unwrap();
        Command::new("curl").arg(link.1).arg("-o").arg(full_file).status().unwrap();
        Ok(())
    }
}
