size_t SerializeUInt32(uint32_t i, unsigned char *buf) {
  bytes[0] = (i & 0x000000ff);
  bytes[1] = (i & 0x0000ff00) >> 8;
  bytes[2] = (i & 0x00ff0000) >> 16;
  bytes[3] = (i & 0xff000000) >> 24;
  return 4;
}

size_t DeserializeUInt32(unsigned char *buf, uint32_t& i) {
  i = std::uint32_t(buf[0]) + (std::uint32_t(buf[1]) << 8)
    + (std::uint32_t(buf[2]) << 16) + (std::uint32_t(buf[3]) << 24);
  return 4;
}
