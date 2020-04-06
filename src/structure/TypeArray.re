open Js.Typed_array;

module Uint32Array = {
  let setArray = (offset, target: array(int), source) => {
    source |> Uint32Array.setArrayOffset(target, offset);

    (source, offset + (target |> Js.Array.length));
  };
};

module Float32Array = {
  let setArray = (offset, target: array(float), source) => {
    source |> Float32Array.setArrayOffset(target, offset);

    (source, offset + (target |> Js.Array.length));
  };

  let setFloat32Array = (offset, target: Float32Array.t, source) => {
    source |> Float32Array.setArrayOffset(Obj.magic(target), offset);

    (source, offset + (target |> Float32Array.length));
  };

  let setFloatTuple3 = (offset, target: ColorType.color3, source) => {
    source |> Float32Array.setArrayOffset(Obj.magic(target), offset);

    (source, offset + 3);
  };

  let setFloat = (offset, target: float, source) => {
    Float32Array.unsafe_set(source, offset, target);

    (source, offset + 1);
  };
};
