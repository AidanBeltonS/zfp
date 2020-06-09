static CFP_ARRAY_TYPE
_t1(CFP_ARRAY_TYPE, ctor)(size_t nx, size_t ny, double rate, const ZFP_SCALAR_TYPE * p, size_t csize)
{
  CFP_ARRAY_TYPE a;
  a.object = static_cast<void*>(new ZFP_ARRAY_TYPE(nx, ny, rate, p, csize));
  return a;
}

static size_t
_t1(CFP_ARRAY_TYPE, size_x)(CFP_ARRAY_TYPE self)
{
  return static_cast<const ZFP_ARRAY_TYPE*>(self.object)->size_x();
}

static size_t
_t1(CFP_ARRAY_TYPE, size_y)(CFP_ARRAY_TYPE self)
{
  return static_cast<const ZFP_ARRAY_TYPE*>(self.object)->size_y();
}

static void
_t1(CFP_ARRAY_TYPE, resize)(CFP_ARRAY_TYPE self, size_t nx, size_t ny, int clear)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.object)->resize(nx, ny, clear);
}

static ZFP_SCALAR_TYPE
_t1(CFP_ARRAY_TYPE, get)(CFP_ARRAY_TYPE self, size_t i, size_t j)
{
  return static_cast<const ZFP_ARRAY_TYPE*>(self.object)->operator()(i, j);
}

static void
_t1(CFP_ARRAY_TYPE, set)(CFP_ARRAY_TYPE self, size_t i, size_t j, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.object)->operator()(i, j) = val;
}

static CFP_REF_TYPE
_t1(CFP_ARRAY_TYPE, ref)(CFP_ARRAY_TYPE self, size_t i, size_t j)
{
  CFP_REF_TYPE r;
  r.i = i;
  r.j = j;
  r.array = self;
  return r;
}

static CFP_REF_TYPE
_t1(CFP_ARRAY_TYPE, ref_flat)(CFP_ARRAY_TYPE self, size_t i)
{
  CFP_REF_TYPE r;
  r.i = i % static_cast<const ZFP_ARRAY_TYPE*>(self.object)->size_x();
  r.j = i / static_cast<const ZFP_ARRAY_TYPE*>(self.object)->size_x();
  r.array = self;
  return r;
}

static CFP_PTR_TYPE
_t1(CFP_ARRAY_TYPE, ptr)(CFP_ARRAY_TYPE self, size_t i, size_t j)
{
  CFP_PTR_TYPE p;
  p.reference = _t1(CFP_ARRAY_TYPE, ref)(self, i, j);
  return p;
}

static CFP_PTR_TYPE
_t1(CFP_ARRAY_TYPE, ptr_flat)(CFP_ARRAY_TYPE self, size_t i)
{
  CFP_PTR_TYPE p;
  p.reference = _t1(CFP_ARRAY_TYPE, ref_flat)(self, i);
  return p;
}

static CFP_ITER_TYPE
_t1(CFP_ARRAY_TYPE, begin)(CFP_ARRAY_TYPE self)
{
  CFP_ITER_TYPE it;
  it.i = 0;
  it.j = 0;
  it.array = self;
  return it;
}

static CFP_ITER_TYPE
_t1(CFP_ARRAY_TYPE, end)(CFP_ARRAY_TYPE self)
{
  CFP_ITER_TYPE it;
  it.i = 0;
  it.j = static_cast<const ZFP_ARRAY_TYPE*>(self.object)->size_y();
  it.array = self;
  return it;
}

static ZFP_SCALAR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_REF_TYPE, get)(CFP_REF_TYPE self)
{
  return static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->operator()(self.i, self.j);
}

static void
_t2(CFP_ARRAY_TYPE, CFP_REF_TYPE, set)(CFP_REF_TYPE self, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.array.object)->operator()(self.i, self.j) = val;
}

static void
_t2(CFP_ARRAY_TYPE, CFP_REF_TYPE, copy)(CFP_REF_TYPE self, CFP_REF_TYPE src)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.array.object)->operator()(self.i, self.j) =
    static_cast<const ZFP_ARRAY_TYPE*>(src.array.object)->operator()(src.i, src.j);
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, lt)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  size_t selfIdx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x());
  size_t srcIdx = (int)(src.reference.i + src.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(src.reference.array.object)->size_x());

  return selfIdx < srcIdx && 
         self.reference.array.object == src.reference.array.object;
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, gt)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  size_t selfIdx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x());
  size_t srcIdx = (int)(src.reference.i + src.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(src.reference.array.object)->size_x());

  return selfIdx > srcIdx && 
         self.reference.array.object == src.reference.array.object;
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, leq)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  size_t selfIdx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x());
  size_t srcIdx = (int)(src.reference.i + src.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(src.reference.array.object)->size_x());

  return selfIdx <= srcIdx && 
         self.reference.array.object == src.reference.array.object;
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, geq)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  size_t selfIdx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x());
  size_t srcIdx = (int)(src.reference.i + src.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(src.reference.array.object)->size_x());

  return selfIdx >= srcIdx && 
         self.reference.array.object == src.reference.array.object;
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, eq)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  return self.reference.i == src.reference.i && 
         self.reference.j == src.reference.j &&
         self.reference.array.object == src.reference.array.object;
}

static int
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, neq)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  return self.reference.i != src.reference.i || 
         self.reference.j != src.reference.j ||
         self.reference.array.object != src.reference.array.object;
}

static ptrdiff_t
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, distance)(CFP_PTR_TYPE self, CFP_PTR_TYPE src)
{
  return (self.reference.i + self.reference.j * static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x()) -
         (src.reference.i + src.reference.j * static_cast<const ZFP_ARRAY_TYPE*>(src.reference.array.object)->size_x());
}

static CFP_PTR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, next)(CFP_PTR_TYPE self, ptrdiff_t d)
{
  size_t idx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x()) + d;

  self.reference.i = idx % static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();
  self.reference.j = idx / static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();

  return self;  
}

static CFP_PTR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, prev)(CFP_PTR_TYPE self, ptrdiff_t d)
{
  size_t idx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x()) - d;

  self.reference.i = idx % static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();
  self.reference.j = idx / static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();

  return self;  
}

static ZFP_SCALAR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, get)(CFP_PTR_TYPE self)
{
  return static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->operator()(self.reference.i, self.reference.j);
}

static ZFP_SCALAR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, get_at)(CFP_PTR_TYPE self, ptrdiff_t d)
{
  self = _t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, next)(self, d);
  return static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->operator()(self.reference.i, self.reference.j);
}

static void
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, set)(CFP_PTR_TYPE self, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.reference.array.object)->operator()(self.reference.i, self.reference.j) = val;
}

static void
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, set_at)(CFP_PTR_TYPE self, ZFP_SCALAR_TYPE val, ptrdiff_t d)
{
  self = _t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, next)(self, d);
  static_cast<ZFP_ARRAY_TYPE*>(self.reference.array.object)->operator()(self.reference.i, self.reference.j) = val;
}

static CFP_PTR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, inc)(CFP_PTR_TYPE self)
{
  size_t idx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x()) + 1;

  self.reference.i = idx % static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();
  self.reference.j = idx / static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();

  return self;  
}

static CFP_PTR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, dec)(CFP_PTR_TYPE self)
{
  size_t idx = (int)(self.reference.i + self.reference.j*static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x()) - 1;

  self.reference.i = idx % static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();
  self.reference.j = idx / static_cast<const ZFP_ARRAY_TYPE*>(self.reference.array.object)->size_x();

  return self;  
}

static CFP_REF_TYPE
_t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, ref_at)(CFP_PTR_TYPE self, ptrdiff_t d)
{
  self = _t2(CFP_ARRAY_TYPE, CFP_PTR_TYPE, next)(self, d);
  return self.reference;
}

static void
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, set)(CFP_ITER_TYPE self, ZFP_SCALAR_TYPE val)
{
  static_cast<ZFP_ARRAY_TYPE*>(self.array.object)->operator()(self.i, self.j) = val;
}

static ZFP_SCALAR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, get)(CFP_ITER_TYPE self)
{
  return static_cast<ZFP_ARRAY_TYPE*>(self.array.object)->operator()(self.i, self.j);
}

static CFP_REF_TYPE
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, ref)(CFP_ITER_TYPE self)
{
  CFP_REF_TYPE r;
  r.i = self.i;
  r.j = self.j;
  r.array = self.array;
  return r;
}

static CFP_PTR_TYPE
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, ptr)(CFP_ITER_TYPE self)
{
  CFP_REF_TYPE r;
  r.i = self.i;
  r.j = self.j;
  r.array = self.array;
  CFP_PTR_TYPE p;
  p.reference = r;
  return p;
}

static CFP_ITER_TYPE
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, inc)(CFP_ITER_TYPE self)
{
  CFP_ITER_TYPE it = self;
  size_t nx = static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->size_x();
  size_t ny = static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->size_y();

  it.i++;
  if (!(it.i & 3u) || it.i == nx) {
    it.i = (it.i - 1) & ~3u;
    it.j++;
    if (!(it.j & 3u) || it.j == ny) {
      it.j = (it.j - 1) & ~3u;
      // done with block; advance to next
      if ((it.i += 4) >= nx) {
        it.i = 0;
        if ((it.j += 4) >= ny)
          it.j = ny;
      }
    }
  }
  return it;
}

static CFP_ITER_TYPE
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, next)(CFP_ITER_TYPE self, ptrdiff_t d)
{
  size_t idx = (int)(self.i + self.j*static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->size_x()) + d;

  self.i = idx % static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->size_x();
  self.j = idx / static_cast<const ZFP_ARRAY_TYPE*>(self.array.object)->size_x();

  return self;  
}

static int
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, eq)(CFP_ITER_TYPE self, CFP_ITER_TYPE src)
{
  return (self.i == src.i &&
          self.j == src.j &&
          self.array.object == src.array.object);
}

static int
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, neq)(CFP_ITER_TYPE self, CFP_ITER_TYPE src)
{
  return (self.i != src.i || 
          self.j != src.j || 
          self.array.object != src.array.object);
}

static size_t
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, i)(CFP_ITER_TYPE self)
{
  return self.i;
}

static size_t
_t2(CFP_ARRAY_TYPE, CFP_ITER_TYPE, j)(CFP_ITER_TYPE self)
{
  return self.j;
}
