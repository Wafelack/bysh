mod wanager;
use std::io::{Error, ErrorKind};
use wanager::Wanager;

#[allow(unused_variables)]
pub fn install(lib: &str) -> std::io::Result<()> {
    let w = Wanager;
    if !w.exists(lib) {
        return Err(Error::new(ErrorKind::NotFound, "Library does not exists !"));
    }
    Ok(())
}
