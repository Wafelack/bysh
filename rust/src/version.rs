pub struct Version {
    pub main: u8,
    pub discriminator: u8,
    pub third: u8,
}
pub fn version(version: Version) {
    println!("Wanager, by Wafelack <contactme.wafelack@protonmail.com>, licensed under GPL v3.0, Version {}.{}.{}", version.main, version.discriminator, version.third);
}
